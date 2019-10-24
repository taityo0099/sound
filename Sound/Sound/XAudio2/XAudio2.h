#pragma once
#include "../Base/Singleton.h"

struct IXAudio2;
struct IXAudio2MasteringVoice;

class XAudio2 :
	public Singleton<XAudio2>
{
	friend Singleton<XAudio2>;
public:
	// エンジン開始
	void EngineStart(void);

	// エンジン停止
	void EngineStop(void);

	// オーディオ取得
	IXAudio2* GetAudio(void) const;

	// マスタリング取得
	IXAudio2MasteringVoice* GetMastering(void) const;

private:
	// コンストラクタ
	XAudio2();
	// デストラクタ
	~XAudio2();

	// オーディオ生成
	void CreateAudio(void);

	// マスタリング生成
	void CreateMastring(void);


	// オーディオ
	IXAudio2* audio;

	// マスタリング
	IXAudio2MasteringVoice* mastering;
};
