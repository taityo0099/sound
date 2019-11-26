#include <xaudio2.h>
#include <wrl.h>
#include "SoundBox/XAudio2//XAudio2.h"
#include "SoundBox/Voice/Voice.h"
#include <Windows.h>
#include "SoundBox/Info.h"

#define Desctory(X) { if((X) != nullptr) (X)->DestroyVoice(); (X) = nullptr;}

#pragma comment(lib,"XAudio2.lib")

int main()
{
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);

	bool play = false;
	bool key = false;
	
	XAudio2::Get().EngineStart();
	Voice* voice = new Voice("sample3.wav");

	//ƒL[“ü—Í
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

	CoUninitialize();
	return 0;
}