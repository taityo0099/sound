#pragma once
#include "../Base/Singleton.h"

struct IXAudio2;
struct IXAudio2MasteringVoice;

class XAudio2 :
	public Singleton<XAudio2>
{
public:
	// エンジン開始
	bool EngineStart(void);

	// エンジン終了
	void EngineEnd(void);

	// オーディオ取得
	IXAudio2* Audio(void) const;

private:
	// コンストラクタ
	XAudio2();
	// デストラクタ
	~XAudio2();

	// オーディオの生成
	long CreateAudio(void);

	// マスタリングボイスの生成
	long CreateMastering(void);


	// オーディオ
	IXAudio2* audio;

	// マスタリングボイス
	IXAudio2MasteringVoice* mastering;
};
