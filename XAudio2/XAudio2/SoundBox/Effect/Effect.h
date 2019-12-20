#pragma once
#include <string>
#include <vector>



class Effect
{

public:
	
};



class Filter :public Effect
{
public:
	//コンストラクタ
	Filter();

	//デストラクタ
	~Filter();

	// ローパスフィルター
	void LowPass(const unsigned int  & sample,const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));
	
	//ハイパスフィルター
	void HighPass(const unsigned int & sample, const unsigned int & cutoff, const float& q = 1.0f / std::sqrt(2.0f));

	//実行
	void Execution(const std::vector<float>& input);

	// 参照ファイル名
	std::string name;

	Filter(const Filter&) = delete;
	void operator=(const Filter&) = delete;

	//入力値
	float in[2];

	//出力値
	float out[2];

	//フィルター係数
	float a[2];
	float b[2];
};

//class Volume
//{
//public:
//	Volume();
//	~Volume();
//
//private:
//	//音量
//	float volume;
//};