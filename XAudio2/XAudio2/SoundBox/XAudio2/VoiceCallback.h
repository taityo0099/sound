#pragma once
<<<<<<< HEAD
<<<<<<< Updated upstream
#include "../Voice.h"
=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
#include "../Voice/Voice.h"
#include <xaudio2.h>



class VoiceCallback :
	public IXAudio2VoiceCallback
{
public:
	// �R���X�g���N�^
<<<<<<< HEAD
	VoiceCallback() {
	}
=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	VoiceCallback(Voice* voice) : voice(voice) {}
	// �f�X�g���N�^
	~VoiceCallback() {}

	// �f�[�^�ǂݍ��ݑO�ɌĂяo��
	void __stdcall OnVoiceProcessingPassStart(unsigned int SamplesRequired)
	{
		voice->Submit();
	}

	// �V�����o�b�t�@�̏����J�n���ɌĂяo��
	void __stdcall OnBufferStart(void* pBufferContext) {
	}

	// �o�b�t�@�̏����I�����ɌĂяo��
	void __stdcall OnBufferEnd(void* pBufferContext)
	{
		voice->CheckEnd();
	}

	// �����̏����p�X�I�����ɌĂяo��
	void __stdcall OnVoiceProcessingPassEnd(void) {
	}

	// �A�������X�g���[���Đ��I�����ɌĂяo��
	void __stdcall OnStreamEnd(void) {
	}

	// ���[�v�I���ʒu���B���ɌĂяo��
	void __stdcall OnLoopEnd(void* pBufferContext) {
	}

	// �G���[�������ɌĂяo��
	void __stdcall OnVoiceError(void* pBufferContext, long Error) {
	}

private:
	// �T�E���h���C�u����
	Voice* voice;
};