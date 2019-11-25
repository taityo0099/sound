#include "Filter.h"
#include<wrl.h>


//Filter::Filter() : 
//	threadEnd(false)
//{
//	/*if (th.joinable() == false)
//	{
//		th = std::thread(&Filter::Stream, this);
//	}*/
//	/*voice->lowPassFilter(100, 1.0f);*/
//}
//
//
//Filter::~Filter()
//{
//	/*threadEnd = true;
//	if (th.joinable() == true)
//	{
//		th.join();
//	}*/
//}


void Filter::lowPassFilter(unsigned int catf, float q)
{
	//snd::Info info = Loader::Get().GetInfo(name);

	////メンバー変数を初期化
	//a0 = 1.0f; // 0以外にしておかないと除算でエラーになる
	//a1 = 0.0f;
	//a2 = 0.0f;
	//b0 = 1.0f;
	//b1 = 0.0f;
	//b2 = 0.0f;

	//in1 = 0.0f;
	//in2 = 0.0f;

	//out1 = 0.0f;
	//out2 = 0.0f;

	////フィルター
	//float omega = 2.0f * MPI * catf / info.sample;
	//float alpha = sin(omega) / (2.0f * q);

	//a0 = 1.0f + alpha;
	//a1 = -2.0f * cos(omega);
	//a2 = 1.0f * alpha;
	//b0 = (1.0f - cos(omega)) / 2.0f;
	//b1 = 1.0f - cos(omega);
	//b2 = (1.0f - cos(omega)) / 2.0f;

	//for (int i = 0; i < size; i++)
	//{
	//	float out = b0 / a0 * tmp[i] + b1 / a0 * in1 + b2 / a0 * in2
	//									- a1 / a0 * out1 - a2 / a0 * out2;

	//	in2 = in1;
	//	in1 = tmp[i];
	//	
	//	out2 = out1;
	//	out1 = out;

	//	tmp[i] = out;
	//}
	
}


//非同期用の関数
void Filter::Stream()
{
	/*while (!threadEnd)
	{
		printf("フィルター\n");
	}*/
}
