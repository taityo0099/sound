#include <xaudio2.h>
#include <wrl.h>
#include <ks.h>
#include <ksmedia.h>
#include <vector>
#include "XAudio2/XAudio2.h"
#include "Loader/Loader.h"

#pragma comment(lib, "xaudio2.lib")

// スピーカ一覧
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

// 破棄
#define Desctory(X) { if((X) != nullptr) (X)->DestroyVoice(); (X) = nullptr; }

//サンプリング周波数
const unsigned int sample = 44100;
//量子化ビット数
const unsigned int bit = 32;
//チャンネル
const unsigned int channel = 2;

int main()
{
	Loader::Get().Load("Sample.wav");

	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);

	//波形データの情報
	WAVEFORMATEXTENSIBLE fmt{};
	fmt.Format.cbSize               = sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX);
	fmt.Format.nSamplesPerSec       = sample;
	fmt.Format.wBitsPerSample       = bit;
	fmt.Format.nChannels            = channel;
	fmt.Format.nBlockAlign          = fmt.Format.nChannels * fmt.Format.wBitsPerSample / 8;
	fmt.Format.nAvgBytesPerSec      = fmt.Format.nSamplesPerSec * fmt.Format.nBlockAlign;
	fmt.Format.wFormatTag           = WAVE_FORMAT_EXTENSIBLE;
	fmt.dwChannelMask               = spk[fmt.Format.nChannels - 1];
	fmt.Samples.wValidBitsPerSample = fmt.Format.wBitsPerSample;
	fmt.SubFormat                   = KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;

	XAudio2::Get().EngineStart();


	/*{
		//オーディオ
		Microsoft::WRL::ComPtr<IXAudio2>audio = nullptr;
		{
			 hr = XAudio2Create(&audio);
			_ASSERT(hr == S_OK);
		}
		//マスタリング
		IXAudio2MasteringVoice* mastering = nullptr;
		{
			hr = audio->CreateMasteringVoice(&mastering);
			_ASSERT(hr == S_OK);
		}

		//ソースボイス
		IXAudio2SourceVoice* voice = nullptr;
		{
			hr = audio->CreateSourceVoice(&voice, (WAVEFORMATEX*)&fmt, 0, 1.0f, nullptr);
			_ASSERT(hr == S_OK);
		}

		//「ラ」の音
		std::vector<float>A(sample * channel);
		{
			for (size_t i = 0; i < A.size(); i += channel)
			{
				A[i] = std::sin(2.0f * std::acos(-1.0f) * 440.0f * i / float(sample));
				A[i + 1] = A[i];
			}
		}

		//波形をバッファに乗せる
		{
			XAUDIO2_BUFFER buffer{};
			buffer.AudioBytes = sizeof(A[0]) * A.size();
			buffer.pAudioData = (unsigned char*)A.data();
			hr = voice->SubmitSourceBuffer(&buffer);
			_ASSERT(hr == S_OK);
		}

		//再生
		{
			hr = voice->Start();
			_ASSERT(hr == S_OK);
		}

		//スレッド待機
		Sleep(10000);

		//停止
		{
			hr = voice->Stop();
			_ASSERT(hr == S_OK);
		}

		Desctory(voice);
		Desctory(mastering);
	}*/

	CoUninitialize();
	return 0;
}
