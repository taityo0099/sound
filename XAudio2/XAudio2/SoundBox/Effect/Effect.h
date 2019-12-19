#pragma once
#include <string>
#include <vector>


#define MPI  3.14159265


class Effect
{

public:
	
};


class Volume :public Effect
{
public:
	Volume();
	~Volume();

	
private:
	//����
	float volume;
};



class Filter :public Effect
{
public:
	//�R���X�g���N�^
	Filter();

	//�f�X�g���N�^
	~Filter();

	// ���[�p�X�t�B���^�[
	void LowPass(const unsigned int  & sample,const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));
	
	//�n�C�p�X�t�B���^�[
	void HighPass(const unsigned int & sample, const unsigned int & cutoff, const float& q = 1.0f / std::sqrt(2.0f));

	//���s
	void Execution(const std::vector<float>& input);

	// �Q�ƃt�@�C����
	std::string name;

	Filter(const Filter&) = delete;
	void operator=(const Filter&) = delete;

	//���͒l
	float in[2];

	//�o�͒l
	float out[2];

	//�t�B���^�[�W��
	float a[2];
	float b[2];
};