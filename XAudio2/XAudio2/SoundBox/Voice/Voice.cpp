#include "Voice.h"
#include "../XAudio2/XAudio2.h"
#include "../XAudio2/VoiceCallback.h"
#include "../Loader/Loader.h"
#include<wrl.h>
#include<ks.h>
#include<ksmedia.h>

const unsigned long spk[] = {
	KSAUDIO_SPEAKER_MONO,
	KSAUDIO_SPEAKER_STEREO,
	KSAUDIO_SPEAKER_STEREO | SPEAKER_LOW_FREQUENCY,
	KSAUDIO_SPEAKER_QUAD,
	0,
	KSAUDIO_SPEAKER_5POINT1,
	0,
	KSAUDIO_SPEAKER_7POINT1_SURROUND
};


// コンストラクタ
Voice::Voice(const std::string & fileName) : read(0),loop(false),end(false),voice(nullptr)
{
	back = std::make_unique<VoiceCallback>(this);

	Load(fileName);
	CreateVoice();

}

// デストラクタ
Voice::~Voice()
{
	if (voice != nullptr)
	{
		voice->DestroyVoice();
	}
}

// 読み込み
int Voice::Load(const std::string & fileName)
{
	auto hr = Loader::Get().Load(fileName);
	if (hr == 0)
	{
		name = fileName;
	}
	return hr;
}

// ソースボイス生成
void Voice::CreateVoice(void)
{
	snd::Info info = Loader::Get().GetInfo(name);

	//波形データの情報
	WAVEFORMATEXTENSIBLE fmt{};
	fmt.Format.cbSize = sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX);
	fmt.Format.nSamplesPerSec = info.sample;
	fmt.Format.wBitsPerSample = sizeof(float) * 8;
	fmt.Format.nChannels = info.channel;
	fmt.Format.nBlockAlign = fmt.Format.nChannels * fmt.Format.wBitsPerSample / 8;
	fmt.Format.nAvgBytesPerSec = fmt.Format.nSamplesPerSec * fmt.Format.nBlockAlign;
	fmt.Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;

	fmt.dwChannelMask = spk[fmt.Format.nChannels - 1];
	fmt.Samples.wValidBitsPerSample = fmt.Format.wBitsPerSample;
	fmt.SubFormat = KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;

	auto hr = XAudio2::Get().GetAudio()->CreateSourceVoice(&voice, (WAVEFORMATEX*)&fmt, 0, 1.0f, &(*back));
	_ASSERT(hr == S_OK);

}

// 再生
void Voice::Play(const bool & loop)
{
	auto hr = voice->Start();
	_ASSERT(hr == S_OK);

	this->loop = loop;
}

// 停止
void Voice::Stop(void)
{
	auto hr = voice->Stop();
	_ASSERT(hr == S_OK);
}

// バッファに波形を乗せる
void Voice::Submit(void)
{
	static std::vector<float>tmp;

	//三項演算子
	size_t size = (read + Loader::Get().GetFrame(name) >= Loader::Get().GetWave(name)->size())
		? read + Loader::Get().GetFrame(name) - Loader::Get().GetWave(name)->size()
		: Loader::Get().GetFrame(name);
	/*size_t size;
	if (read + Loader::Get().GetFrame(name) > Loader::Get().GetWave(name)->size())
	{
		size = read + Loader::Get().GetFrame(name) - Loader::Get().GetWave(name)->size();
	}
	else
	{
		size = Loader::Get().GetFrame(name);
	}*/


	tmp.assign(&Loader::Get().GetWave(name)->at(read), &Loader::Get().GetWave(name)->at(read + size));

	for (auto& i : tmp)
	{
		i *= volume;
	}

	XAUDIO2_BUFFER buffer{};
	buffer.AudioBytes = sizeof(float) * size;
	buffer.pAudioData = (unsigned char*)tmp.data();
	auto hr = voice->SubmitSourceBuffer(&buffer);
	_ASSERT(hr == S_OK);

	read += size;
}

// 波形を全部読みこんだか判定
void Voice::CheckEnd(void)
{
	if (read >= Loader::Get().GetWave(name)->size())
	{
		if (loop == false)
		{
			Stop();
		}
		read = 0;
	}
}
