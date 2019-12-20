#pragma once
#include<string>
#include<xaudio2.h>
#include<thread>
#include<vector>

struct  Voice;

class Effecter
{
	friend Voice;
public:
	Effecter();
	~Effecter();

private:
	// スレッド終了フラグ
	bool threadEnd;

	//非同期用の関数
	void Stream(void);

	XAUDIO2_FILTER_TYPE* filter;

	//スレッド
	std::thread th;

	//ミューテックス
	std::mutex mtx;

};