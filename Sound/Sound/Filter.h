#pragma once
#include <string>
#include <xaudio2.h>
#include <thread>


#define MPI 3.1415926536			//�~����


class Filter
{
public:
	Filter() {};
	~Filter() {};

	//���[�p�X
	void lowPassFilter(unsigned int, float);

private:
	// �X���b�h
	std::thread th;

	// �X���b�h�I���t���O
	bool threadEnd;

	//�񓯊��p�̊֐�
	void Stream(void);

	//�t�B���^�[�W��
	float a0, a1, a2;

	float b0, b1, b2;

	//�o�͒l
	float out1, out2;

	//���͒l
	float in1, in2;

	XAUDIO2_FILTER_TYPE* filter;
};

