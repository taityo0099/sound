#include "XAudio2.h"
#include <xaudio2.h>
#include <crtdbg.h>

// �R���X�g���N�^
XAudio2::XAudio2() : 
	audio(nullptr), mastering(nullptr)
{
}

// �f�X�g���N�^
XAudio2::~XAudio2()
{
	EngineStop();
}

// �G���W���J�n
void XAudio2::EngineStart(void)
{
	CreateAudio();
	CreateMastring();
}

// �G���W����~
void XAudio2::EngineStop(void)
{
	if (mastering != nullptr)
	{
		mastering->DestroyVoice();
	}
	if (audio != nullptr)
	{
		audio->Release();
	}
}

// �I�[�f�B�I����
void XAudio2::CreateAudio(void)
{
	auto hr = XAudio2Create(&audio);
	_ASSERT(hr == S_OK);
}

// �}�X�^�����O����
void XAudio2::CreateMastring(void)
{
	auto hr = audio->CreateMasteringVoice(&mastering);
	_ASSERT(hr == S_OK);
}

// �I�[�f�B�I�擾
IXAudio2 * XAudio2::GetAudio(void) const
{
	return audio;
}

// �}�X�^�����O�擾
IXAudio2MasteringVoice * XAudio2::GetMastering(void) const
{
	return mastering;
}
