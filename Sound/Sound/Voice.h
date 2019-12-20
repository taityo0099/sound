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
	// コンストラクタ
	Voice(const std::string& fileName);

	// 読み込み
	int Load(const std::string& fileName);


	// 再生
	void Play(const bool& loop = false);

	// 停止
	void Stop(void);

	// ローパス設定
	void LowPass(const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));

	// ハイパス設定
	void HighPass(const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));



	// フィルタ実行
	std::vector<float> Filter(const std::vector<float>& data);

	// デストラクタ
	~Voice();


	//音量
	float volume;

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

	// コールバック
	std::unique_ptr<VoiceCallback>back;

	// フィルタ係数
	std::array<float, 3>a;
	// フィルタ係数
	std::array<float, 3>b;
	//過去入力データ
	std::array<float, 2>input;
	//過去出力データ
	std::array<float, 2>output;
};