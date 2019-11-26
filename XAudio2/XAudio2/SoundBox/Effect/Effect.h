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
	//音量
	float volume;
};
class Filter :public Effect
{
public:
	// ローパスフィルター
	void LowPass(const unsigned int& cutoff, const float& q = 1.0f / std::sqrt(2.0f));
	
	//ハイパスフィルター
	void HighPass(const unsigned int & cutoff, const float& q = 1.0f / std::sqrt(2.0f));

private:
	
};