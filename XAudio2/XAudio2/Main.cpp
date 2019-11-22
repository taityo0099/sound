#include <xaudio2.h>
#include <wrl.h>
#include "SoundBox/XAudio2//XAudio2.h"

#pragma comment(lib,"XAudio2.lib")

int main()
{
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);

	bool play = false;
	bool key = false;
	
	XAudio2::Get().EngineStart();
	//Voice* voice = new Voice("sample1.wav");

	//キー入力
	while (!(GetKeyState(VK_ESCAPE) & 0x80))
	{
		if (GetKeyState(VK_SPACE) & 0x80)
		{
			if (key == false)
			{
				key = true;
				if (play == true)
				{
					play = true;
				}
				else
				{
					play = false;
				}
			}
			else
			{
				key = false;
			}
		}
		if (play == true)
		{
			//ボリューム変更
		}
	}

	//delete voice;

	CoUninitialize();
	return 0;
}