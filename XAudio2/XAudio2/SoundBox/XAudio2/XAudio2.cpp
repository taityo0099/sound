#include "XAudio2.h"
#include <xaudio2.h>
#include <crtdbg.h>

//コンストラクタ
XAudio2::XAudio2() // : audio(nullptr),mastering(nullptr)
{
	audio		= nullptr;
	mastering	= nullptr;
}

//デストラクタ
XAudio2::~XAudio2()
{
	EngineStop();
}





//エンジン開始
void XAudio2::EngineStart(void)
{
	CreateAudio();
	CreateMastering();

#ifdef _DEBUG
	XAUDIO2_DEBUG_CONFIGURATION debug{};
	debug.BreakMask = XAUDIO2_LOG_ERRORS;
	debug.TraceMask = XAUDIO2_LOG_ERRORS | XAUDIO2_LOG_WARNINGS;
	audio->SetDebugConfiguration(&debug);
#endif
}


//エンジン停止
void XAudio2::EngineStop(void)
{
}
//オーディオ取得
IXAudio2 * XAudio2::GetAudio(void)
{
	return nullptr;
}

IXAudio2MasteringVoice * XAudio2::GetMastering(void) const
{
	return nullptr;
}

//オーディオ生成
void XAudio2::CreateAudio(void)
{

}

void XAudio2::CreateMastering(void)
{

}