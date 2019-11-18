#pragma once
#include <string>
#include <xaudio2.h>
#include<thread>


#define MPI 3.1415926536			//円周率


class Filter
{
public:
	Filter();
	~Filter();

	//ローパス
	void lowPassFilter(unsigned int, float);

private:
	// スレッド
	std::thread th;

	// スレッド終了フラグ
	bool threadEnd;

	//非同期用の関数
	void Stream(void);

	//フィルター係数
	float a0, a1, a2;

	float b0, b1, b2;

	//出力値
	float out1, out2;

	//入力値
	float in1, in2;

	XAUDIO2_FILTER_TYPE* filter;
};

