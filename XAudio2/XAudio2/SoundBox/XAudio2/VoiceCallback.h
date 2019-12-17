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
	// コンストラクタ
<<<<<<< HEAD
	VoiceCallback() {
	}
=======
>>>>>>> c662ef88ab90714444cd08206c8a63b83f4316ad
	VoiceCallback(Voice* voice) : voice(voice) {}
	// デストラクタ
	~VoiceCallback() {}

	// データ読み込み前に呼び出し
	void __stdcall OnVoiceProcessingPassStart(unsigned int SamplesRequired)
	{
		voice->Submit();
	}

	// 新しいバッファの処理開始時に呼び出し
	void __stdcall OnBufferStart(void* pBufferContext) {
	}

	// バッファの処理終了時に呼び出し
	void __stdcall OnBufferEnd(void* pBufferContext)
	{
		voice->CheckEnd();
	}

	// 音声の処理パス終了時に呼び出し
	void __stdcall OnVoiceProcessingPassEnd(void) {
	}

	// 連続したストリーム再生終了時に呼び出し
	void __stdcall OnStreamEnd(void) {
	}

	// ループ終了位置到達時に呼び出し
	void __stdcall OnLoopEnd(void* pBufferContext) {
	}

	// エラー発生時に呼び出し
	void __stdcall OnVoiceError(void* pBufferContext, long Error) {
	}

private:
	// サウンドライブラリ
	Voice* voice;
};