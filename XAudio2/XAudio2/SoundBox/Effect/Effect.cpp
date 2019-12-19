#include "Effect.h"
#include "../Info.h"



//コンストラクタ
Filter::Filter()
{
	memset(&in[0], 0, sizeof(in));
	memset(&out[0], 0, sizeof(out));
	memset(&a[0], 0, sizeof(a));
	memset(&b[0], 0, sizeof(b));
	a[0] = 1.0f;
	b[0] = 1.0f;

}

//デストラクタ
Filter::~Filter()
{
}

// ローパスフィルター
void Filter::LowPass(const unsigned int & sample,const unsigned int & cutoff, const float & q)
{
	float omega = 2.0f * MPI * cutoff / sample;
	float alpha = std::sin(omega) / (2.0f * q);

	a[0] = 1.0f + alpha;
	a[1] = -2.0f * std::cos(omega);
	a[2] = 1.0f - alpha;

	b[0] = (1.0f - std::cos(omega)) / 2.0f;
	b[1] = 1.0f - std::cos(omega);
	b[2] = (1.0f - std::cos(omega)) / 2.0f;
}

//ハイパスフィルター
void Filter::HighPass(const unsigned int & sample, const unsigned int & cutoff, const float & q)
{
	float omega = 2.0f * MPI * q / sample;
	float alpha = sin(omega) / (2.0f * q);

	a[0] = 1.0f + alpha;
	a[1] = -2.0f * cos(alpha);
	a[2] = 1.0f + alpha;

	b[0] = (1.0f + cos(omega)) / 2.0f;
	b[1] = -(1.0f + cos(omega));
	b[2] = (1.0f + cos(omega)) / 2.0f;
}

//実行
void Filter::Execution(const std::vector<float>& in)
{
	{
		
	}
}

Volume::Volume()
{
	volume = 1.0f;
}

Volume::~Volume()
{
}
