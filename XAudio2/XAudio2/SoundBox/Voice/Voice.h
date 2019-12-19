#pragma once
#include <string>
#include <array>
#include <vector>
#include <memory>

#define MPI 3.1415926536			//円周率



struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	//コンストラクタ
	Voice(const std::string& fileName);
	//デストラクタ
	~Voice();

	//読み込み
	int Load(const std::string& fileName);

	//再生
	void Play(const bool& loop = false);

	//停止
	void Stop(void);


private:

	//音量
	float volume;

private:
	//ソースボイス生成
	void CreateVoice(void);

	//バッファに波形を乗せる
	void Submit(void);


	//波形を全部読みこんだか判定
	void CheckEnd(void);

	//参照ファイル名
	std::string name;

	//読み込み位置
	size_t read;

	//ループフラグ
	bool loop;

	//終了フラグ
	bool end;

	//ソースボイス
	IXAudio2SourceVoice* voice;

	//コールバック
	std::unique_ptr<VoiceCallback>back;
};