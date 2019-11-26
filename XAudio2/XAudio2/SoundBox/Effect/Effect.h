#pragma once
#include <array>

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
	// ���[�p�X�t�B���^�[
	void LowPass(const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));
	
	//�n�C�p�X�t�B���^�[
	void HighPass(const unsigned int & cutoff, const float& q = 1.0f / std::sqrt(2.0f));

private:
	
};