#include "XAudio2.h"
#include <xaudio2.h>
#include <crtdbg.h>

#pragma comment(lib, "xaudio2.lib")

// �R���X�g���N�^
XAudio2::XAudio2() : 
	audio(nullptr), mastering(nullptr)
{
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);
}

// �f�X�g���N�^
XAudio2::~XAudio2()
{
	EngineEnd();
	CoUninitialize();
}

// �I�[�f�B�I�̐���
long XAudio2::CreateAudio(void)
{
	return 0;
}

// �}�X�^�����O�{�C�X�̐���
long XAudio2::CreateMastering(void)
{
	return 0;
}

// �G���W���J�n
bool XAudio2::EngineStart(void)
{
	auto hr = CreateAudio();
	if (FAILED(hr))
	{
		return false;
	}

	hr = CreateMastering();
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

// �G���W���I��
void XAudio2::EngineEnd(void)
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

// �I�[�f�B�I�擾
IXAudio2 * XAudio2::Audio(void) const
{
	return audio;
}
