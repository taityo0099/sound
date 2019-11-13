#include "Voice.h"
#include "XAudio2/XAudio2.h"
#include "XAudio2/VoiceCallback.h"
#include "Loader/Loader.h"
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
Voice::Voice(const std::string& fileName) : 
	read(0), loop(false), end(false), voice(nullptr)
{
	back = std::make_unique<VoiceCallback>(this);

	Load(fileName);
	CreateVoice();

	volume = 1.0f;	//
}

// デストラクタ
Voice::~Voice()
{
	if (voice != nullptr)
	{
		voice->DestroyVoice();
	}
}

//読み込み
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
	fmt.Format.cbSize			= sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX);
	fmt.Format.nSamplesPerSec	= info.sample;
	fmt.Format.wBitsPerSample	= sizeof(float) * 8;
	fmt.Format.nChannels		= info.channel;
	fmt.Format.nBlockAlign		= fmt.Format.nChannels * fmt.Format.wBitsPerSample / 8;
	fmt.Format.nAvgBytesPerSec	= fmt.Format.nSamplesPerSec * fmt.Format.nBlockAlign;
	fmt.Format.wFormatTag		= WAVE_FORMAT_EXTENSIBLE;

	fmt.dwChannelMask			    = spk[fmt.Format.nChannels - 1];
	fmt.Samples.wValidBitsPerSample = fmt.Format.wBitsPerSample;
	fmt.SubFormat					= KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;

	auto hr = XAudio2::Get().GetAudio()->CreateSourceVoice(&voice, (WAVEFORMATEX*)&fmt, 0, 1.0f, &(*back));
	_ASSERT(hr == S_OK);

}

void Voice::lowPassFilter(unsigned int catf, float q)
{
	snd::Info info = Loader::Get().GetInfo(name);

	// メンバー変数を初期化
	a0 = 1.0f; // 0以外にしておかないと除算でエラーになる
	a1 = 0.0f;
	a2 = 0.0f;
	b0 = 1.0f;
	b1 = 0.0f;
	b2 = 0.0f;

	in1 = 0.0f;
	in2 = 0.0f;

	out1 = 0.0f;
	out2 = 0.0f;

	//フィルター
	float omega = 2.0f * MPI * catf / info.sample;
	float alpha = sin(omega) / (2.0f * q);

	a0 = 1.0f + alpha;
	a1 = -2.0f * cos(omega);
	a2 = 1.0f * alpha;
	b0 = (1.0f - cos(omega)) / 2.0f;
	b1 = 1.0f - cos(omega);
	b2 = (1.0f - cos(omega)) / 2.0f;

}

//再生
void Voice::Play(const bool& loop)
{
	auto hr = voice->Start();
	_ASSERT(hr == S_OK);

	this->loop = loop;
}

//停止
void Voice::Stop(void)
{
	auto hr = voice->Stop();
	_ASSERT(hr == S_OK);
}

//バッファに波形を乗せる
void Voice::Submit(void)
{
	static std::vector<float>tmp;	//

	size_t size = (read + Loader::Get().GetFrame(name) > Loader::Get().GetWave(name)->size())
		? read + Loader::Get().GetFrame(name) - Loader::Get().GetWave(name)->size()
		: Loader::Get().GetFrame(name);

	tmp.assign(&Loader::Get().GetWave(name)->at(read), &Loader::Get().GetWave(name)->at(read + size));

	for (int i = 0; i < size; i++)
	{
		float out = b0 / a0 * tmp[i] + b1 / a0 * in1 + b2 / a0 * in2
										- a1 / a0 * out1 - a2 / a0 * out2;

		in2 = in1;
		in1 = tmp[i];
		
		out2 = out1;
		out1 = out;

		tmp[i] = out;
	}

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

//波形を全部読みこんだか判定
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
