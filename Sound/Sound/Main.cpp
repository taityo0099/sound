#include <xaudio2.h>
#include <wrl.h>
#include <ks.h>
#include <ksmedia.h>
#include <vector>
#include "XAudio2/XAudio2.h"
#include "Voice.h"
#include <Windows.h>
#include "Filter.h"
#include "Info.h"

#pragma comment(lib, "xaudio2.lib")

// �X�s�[�J�ꗗ
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

// �j��
#define Desctory(X) { if((X) != nullptr) (X)->DestroyVoice(); (X) = nullptr; }

//�T���v�����O���g��
const unsigned int sample = 44100;
//�ʎq���r�b�g��
const unsigned int bit = 32;
//�`�����l��
const unsigned int channel = 2;

int main()
{
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);

	Filter test;

	bool play = false;
	bool key = false;

	XAudio2::Get().EngineStart();
	Voice* voice = new Voice("sample2.wav");



	//voice->LowPass(1000);
	//voice->HighPass(15000);

	while (!(GetKeyState(VK_ESCAPE) & 0x80))
	{
		if (GetKeyState(VK_SPACE) & 0x80)
		{
			if (key == false)
			{
				key = true;
				play = (play == true) ? false : true;
			}
		}
		else
		{
			key = false;
		}

		if (play == true)
		{
			voice->Play(true);
			if (GetKeyState(VK_UP) & 0x80)
			{
				voice->volume += 0.0001f;
			}
			else if (GetKeyState(VK_DOWN) & 0x80)
			{
				voice->volume -= 0.0001f;
				if (voice->volume < 0.0f)
				{
					voice->volume = 0.0f;
				}
			}
		}
		else
		{
			voice->Stop();
		}

		printf("%f\n", voice->volume);
	}
	delete voice;
	/*{
		//�I�[�f�B�I
		Microsoft::WRL::ComPtr<IXAudio2>audio = nullptr;
		{
			 hr = XAudio2Create(&audio);
			_ASSERT(hr == S_OK);
		}
		//�}�X�^�����O
		IXAudio2MasteringVoice* mastering = nullptr;
		{
			hr = audio->CreateMasteringVoice(&mastering);
			_ASSERT(hr == S_OK);
		}

		//�\�[�X�{�C�X
		IXAudio2SourceVoice* voice = nullptr;
		{

		//�g�`�f�[�^�̏��
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
					hr = audio->CreateSourceVoice(&voice, (WAVEFORMATEX*)&fmt, 0, 1.0f, nullptr);
					_ASSERT(hr == S_OK);
		}

		//�u���v�̉�
		std::vector<float>A(sample * channel);
		{
			for (size_t i = 0; i < A.size(); i += channel)
			{
				A[i] = std::sin(2.0f * std::acos(-1.0f) * 440.0f * i / float(sample));
				A[i + 1] = A[i];
			}
		}

		//�g�`���o�b�t�@�ɏ悹��
		{
			XAUDIO2_BUFFER buffer{};
			buffer.AudioBytes = sizeof(A[0]) * A.size();
			buffer.pAudioData = (unsigned char*)A.data();
			hr = voice->SubmitSourceBuffer(&buffer);
			_ASSERT(hr == S_OK);
		}

		//�Đ�
		{
			hr = voice->Start();
			_ASSERT(hr == S_OK);
		}

		//�X���b�h�ҋ@
		Sleep(10000);

		//��~
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
