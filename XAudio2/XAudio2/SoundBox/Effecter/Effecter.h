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
	// �X���b�h�I���t���O
	bool threadEnd;

	//�񓯊��p�̊֐�
	void Stream(void);

	XAUDIO2_FILTER_TYPE* filter;

	//�X���b�h
	std::thread th;

	//�~���[�e�b�N�X
	std::mutex mtx;

};