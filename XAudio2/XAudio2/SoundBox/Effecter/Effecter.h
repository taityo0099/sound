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
	// �X���b�h
	std::thread th;

	// �X���b�h�I���t���O
	bool threadEnd;

	//�񓯊��p�̊֐�
	void Stream(void);

	XAUDIO2_FILTER_TYPE* filter;
};
