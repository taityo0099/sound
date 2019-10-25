#include "Voice.h"
#include "XAudio2/XAudio2.h"
#include <xaudio2.h>
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

//読み込み
void Voice::Load(const std::string & fileName)
{

}

// ソースボイス生成
void Voice::CreateVoice(void)
{
	//波形データの情報
	WAVEFORMATEXTENSIBLE fmt{};
	fmt.Format.cbSize			= sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX);
	fmt.Format.nSamplesPerSec	= 44100;
	fmt.Format.wBitsPerSample	= 32;
	fmt.Format.nChannels		= 2;
	fmt.Format.nBlockAlign		= fmt.Format.nChannels * fmt.Format.wBitsPerSample / 8;
	fmt.Format.nAvgBytesPerSec	= fmt.Format.nSamplesPerSec * fmt.Format.nBlockAlign;
	fmt.Format.wFormatTag		= WAVE_FORMAT_EXTENSIBLE;
	fmt.dwChannelMask			= spk[fmt.Format.nChannels - 1];
	fmt.Samples.wValidBitsPerSample = fmt.Format.wBitsPerSample;
	fmt.SubFormat					= KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;

	auto hr = XAudio2::Get().GetAudio()->CreateSourceVoice(&voice, (WAVEFORMATEX*)&fmt, 0, 1.0f, nullptr);
	_ASSERT(hr == S_OK);

}

//再生
void Voice::Play(void)
{
}

//停止
void Voice::Stop(void)
{
}

//バッファに波形を乗せる
void Voice::Submit(void)
{
	XAUDIO2_BUFFER buffer{};
	//buffer.AudioBytes
}

//波形を全部読みこんだか判定
void Voice::CheckEnd(void)
{
}
