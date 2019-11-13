#pragma once
#include <string>

#define MPI 3.1415926536			//円周率

struct IXAudio2SourceVoice;
class VoiceCallback;

class Voice
{
	friend VoiceCallback;
public:
	// コンストラクタ
	Voice(const std::string& fileName);

	// 読み込み
	int Load(const std::string& fileName);

	void lowPassFilter(unsigned int, float);

	// 再生
	void Play(const bool& loop = false);

	// 停止
	void Stop(void);

	

	// デストラクタ
	~Voice();


	//音量
	float volume;		//

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

	//フィルター係数
	float a0,a1,a2;

	float b0,b1,b2;




	//出力値
	float out1,out2;
	
	//入力値
	float in1,in2;
	
	// ループフラグ
	bool loop;

	// 終了フラグ
	bool end;

	// ソースボイス
	IXAudio2SourceVoice* voice;

	// コールバック
	std::unique_ptr<VoiceCallback>back;
};
