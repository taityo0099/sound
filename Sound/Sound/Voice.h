#pragma once
#include <string>

struct IXAudio2SourceVoice;

class Voice
{
public:
	// コンストラクタ
	Voice(const std::string& fileName);

	// 読み込み
	void Load(const std::string& fileName);

	// 再生
	void Play(void);

	// 停止
	void Stop(void);

	// デストラクタ
	~Voice();

private:
	// ソースボイス生成
	void CreateVoice(void);

	// バッファに波形を乗せる
	void Submit(void);

	// 波形を全部読みこんだか判定
	void CheckEnd(void);


	// 参照ファイル名
	std::string name;

	// 読み込み位置
	size_t read;

	// ループフラグ
	bool loop;

	// 終了フラグ
	bool end;

	// ソースボイス
	IXAudio2SourceVoice* voice;
};
