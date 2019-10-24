#include "Voice.h"
#include "XAudio2/XAudio2.h"
#include <xaudio2.h>

// コンストラクタ
Voice::Voice(const std::string& fileName) : 
	read(0), loop(false), end(false), voice(nullptr)
{
}

// デストラクタ
Voice::~Voice()
{
	if (voice != nullptr)
	{
		voice->DestroyVoice();
	}
}
