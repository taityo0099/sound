#pragma once
#include<string>
#include<xaudio2.h>
#include<thread>


class Effecter 
{
public:
	Effecter();
	~Effecter();

private:
	// スレッド
	std::thread th;

	// スレッド終了フラグ
	bool threadEnd;

	//非同期用の関数
	void Stream(void);

	XAUDIO2_FILTER_TYPE* filter;
};
