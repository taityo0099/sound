#include "Voice.h"
#include "XAudio2/XAudio2.h"
#include <xaudio2.h>

// �R���X�g���N�^
Voice::Voice(const std::string& fileName) : 
	read(0), loop(false), end(false), voice(nullptr)
{
}

// �f�X�g���N�^
Voice::~Voice()
{
	if (voice != nullptr)
	{
		voice->DestroyVoice();
	}
}
