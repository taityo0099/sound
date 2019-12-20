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
	/*int cnt = 0;
	std::mutex mtx;

	std::thread th1([&](int& cnt)->void 
	{
		std::lock_guard<std::mutex> lock(mtx);
		for (int i = 0; i < 100; ++i)
		{
			++cnt;
			printf("%d\n", cnt);
		}
	}, std::ref(cnt));


	std::thread th2([&](int& cnt)->void 
	{
		std::lock_guard<std::mutex> lock(mtx);
		for (int i = 0; i < 100; ++i)
		{
			++cnt;
			printf("%d\n", cnt);
		}
	}, std::ref(cnt));
	th1.join();
	th2.join();

	printf("%d\n", cnt);*/



















	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);

	bool play = false;
	bool key = false;
	
	XAudio2::Get().EngineStart();
	Voice* voice = new Voice("sample3.wav");


	//ƒL[“ü—Í
	while (!(GetKeyState(VK_ESCAPE) & 0x80))
	{
		if(GetKeyState(VK_SPACE) & 0x80)
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
				voice->volume += 0.001f;
				if (voice->volume > 36.0f)
				{
					voice->volume = 36.0f;
				}
			}
			else if (GetKeyState(VK_DOWN) & 0x80)
			{
				voice->volume -= 0.001f;
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