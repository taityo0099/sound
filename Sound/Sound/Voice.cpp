#include "Voice.h"
#include "XAudio2/XAudio2.h"
#include "XAudio2/VoiceCallback.h"
#include "Loader/Loader.h"
#include "Filter.h"
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
Voice::Voice(const std::string& fileName) : read(0), loop(false), end(false), voice(nullptr)
{
	back = std::make_unique<VoiceCallback>(this);

	Load(fileName);
	CreateVoice();

	volume = 1.0f;	//

	memset(a.data(), sizeof(float) * a.size(), 0);
	memset(b.data(), sizeof(float) * b.size(), 0);
	a[0] = b[0] = 1.0f;
	memset(input.data(), sizeof(float) * input.size(), 0);
	memset(output.data(), sizeof(float) * output.size(), 0);
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

// ローパス設定
void Voice::LowPass(const unsigned int & cutoff, const float & q)
{
	snd::Info info = Loader::Get().GetInfo(name);

	float omega = 2.0f *  MPI * float(cutoff) / float(info.sample);
	float alpha = sin(omega) / (2.0f * q);

	a[0] = 1.0f + alpha;
	a[1] = -2.0f * cos(omega);
	a[2] = 1.0f - alpha;

	b[0] = (1.0f - cos(omega)) / 2.0f;
	b[1] = 1.0f - cos(omega);
	b[2] = (1.0f - cos(omega)) / 2.0f;
}

// ハイパス設定
void Voice::HighPass(const unsigned int & cutoff, const float & q)
{
	snd::Info info = Loader::Get().GetInfo(name);

	float omega = 2.0f * MPI *float(cutoff) / float(info.sample);
	float alpha = sin(omega) / (2.0f * q);

	a[0] = 1.0f + alpha;
	a[1] = -1.0f * cos(omega);
	a[2] = 1.0f - alpha;

	b[0] = alpha;
	b[1] = 0.0f;
	b[2] = -alpha;
}


// フィルタ実行
std::vector<float> Voice::Filter(const std::vector<float>& data)
{
	std::vector<float>tmp(data.size());
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		tmp[i] = b[0] / a[0] * data[i] + b[1] / a[0] * input[0] + b[2] / a[0] * input[1]
			- a[1] / a[0] * output[0] - a[2] / a[0] * output[1];

		std::swap(input[0], input[1]);
		input[0] = data[i];

		std::swap(output[0], output[1]);
		output[0] = tmp[i];
	}

	return tmp;
}

//バッファに波形を乗せる
void Voice::Submit(void)
{
	static std::vector<float>tmp;	//


	//三項演算子
	/*size_t size = (read + Loader::Get().GetFrame(name) > Loader::Get().GetWave(name)->size())
		? read + Loader::Get().GetFrame(name) - Loader::Get().GetWave(name)->size()
		: Loader::Get().GetFrame(name);*/


	//if文
	size_t size;
	if (read + Loader::Get().GetFrame(name) > Loader::Get().GetWave(name)->size())
		
	{
		size = read + Loader::Get().GetFrame(name) - Loader::Get().GetWave(name)->size();
	}
	else
	{
		size = Loader::Get().GetFrame(name);
	}

	tmp.assign(&Loader::Get().GetWave(name)->at(read), &Loader::Get().GetWave(name)->at(read + size));

	tmp = Filter(tmp);

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
