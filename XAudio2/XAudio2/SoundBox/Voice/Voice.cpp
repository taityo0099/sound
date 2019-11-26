#include "Voice.h"
#include "../XAudio2/XAudio2.h"
#include "../XAudio2/VoiceCallback.h"
#include "../Loader/Loader.h"
<<<<<<< Updated upstream
#include <ks.h>
#include <ksmedia.h>
=======
#include<wrl.h>
#include<ks.h>
#include<ksmedia.h>
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream

//�R���X�g���N�^
Voice::Voice(const std::string& fileName):read(0),loop(false),end(false),voice(nullptr)
=======
// �R���X�g���N�^
Voice::Voice(const std::string & fileName) : read(0),loop(false),end(false),voice(nullptr)
>>>>>>> Stashed changes
{
	back = std::make_unique<VoiceCallback>(this);

	Load(fileName);
	CreateVoice();
<<<<<<< Updated upstream
}

//�f�X�g���N�^
Voice::~Voice()
{
}

//�ǂݍ���
int Voice::Load(const std::string& fileName)
=======

	volume = 1.0f;
}

// �f�X�g���N�^
Voice::~Voice()
{
	if (voice != nullptr)
	{
		voice->DestroyVoice();
	}
}

// �ǂݍ���
int Voice::Load(const std::string & fileName)
>>>>>>> Stashed changes
{
	auto hr = Loader::Get().Load(fileName);
	if (hr == 0)
	{
		name = fileName;
	}
	return hr;
}

<<<<<<< Updated upstream
//�Đ�
void Voice::Play(const bool& loop)
{
	auto hr = voice->Start();
	_ASSERT(hr == S_OK);

	this->loop = loop;
}

//��~
void Voice::Stop(void)
{
	auto hr = voice->Stop();
	_ASSERT(hr == S_OK);
}

=======
// �\�[�X�{�C�X����
>>>>>>> Stashed changes
void Voice::CreateVoice(void)
{
	snd::Info info = Loader::Get().GetInfo(name);

	//�g�`�f�[�^�̏��
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
<<<<<<< Updated upstream

}

void Voice::Submit(void)
{
}

=======
}

// �Đ�
void Voice::Play(const bool & loop)
{
	auto hr = voice->Start();
	_ASSERT(hr == S_OK);

	this->loop = loop;
}

// ��~
void Voice::Stop(void)
{
	auto hr = voice->Stop();
	_ASSERT(hr == S_OK);
}

// �o�b�t�@�ɔg�`���悹��
void Voice::Submit(void)
{
	static std::vector<float>tmp;

	//�O�����Z�q
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

// �g�`��S���ǂ݂��񂾂�����
>>>>>>> Stashed changes
void Voice::CheckEnd(void)
{
	if (read >= Loader::Get().GetWave(name)->size())
	{
		if (loop == false)
		{
			Stop();
		}
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
		read = 0;
	}
}
