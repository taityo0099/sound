#include "XAudio2.h"
#include <xaudio2.h>
#include <crtdbg.h>

#pragma comment(lib, "xaudio2.lib")

// コンストラクタ
XAudio2::XAudio2() : 
	audio(nullptr), mastering(nullptr)
{
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	_ASSERT(hr == S_OK);
}

// デストラクタ
XAudio2::~XAudio2()
{
	EngineEnd();
	CoUninitialize();
}

// オーディオの生成
long XAudio2::CreateAudio(void)
{
	return 0;
}

// マスタリングボイスの生成
long XAudio2::CreateMastering(void)
{
	return 0;
}

// エンジン開始
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

// エンジン終了
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

// オーディオ取得
IXAudio2 * XAudio2::Audio(void) const
{
	return audio;
}
