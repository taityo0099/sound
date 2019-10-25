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

// �R���X�g���N�^
Voice::Voice(const std::string& fileName) : 
	read(0), loop(false), end(false), voice(nullptr)
{
	Load(fileName);
	CreateVoice();
}

// �f�X�g���N�^
Voice::~Voice()
{
	if (voice != nullptr)
	{
		voice->DestroyVoice();
	}
}

//�ǂݍ���
void Voice::Load(const std::string & fileName)
{

}

// �\�[�X�{�C�X����
void Voice::CreateVoice(void)
{
	//�g�`�f�[�^�̏��
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

//�Đ�
void Voice::Play(void)
{
}

//��~
void Voice::Stop(void)
{
}

//�o�b�t�@�ɔg�`���悹��
void Voice::Submit(void)
{
	XAUDIO2_BUFFER buffer{};
	//buffer.AudioBytes
}

//�g�`��S���ǂ݂��񂾂�����
void Voice::CheckEnd(void)
{
}
