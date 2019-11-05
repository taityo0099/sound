#include "Func.h"

//離散フーリエ変換
std::vector<std::complex<float>> Func::DFT(const std::vector<float>& data)
{
	std::vector<std::complex<float>>tmp(data.size());

	const std::complex<float>imaginary(0, 1);

	
	//公式のF(t)の枠組み
	for (size_t i = 0; i < data.size(); ++i)
	{
		//公式のΣの枠組み
		for (size_t k = 0; k < data.size(); ++k)
		{
			//Σの中身
			tmp[i] += data[k] * std::exp(-imaginary * 2.0f * std::acos(-1.0f) * float(i * k) / (float)data.size());

		}
	}
	return tmp;

}

std::vector<std::complex<float>> Func::IDFT(const std::vector<float>& Idata)
{
	std::vector<std::complex<float>>inv(Idata.size());

	const std::complex<float>imaginary(0, 1);

	
	//公式のF(t)の枠組み
	for (size_t i = 0; i < Idata.size(); ++i)
	{
		//公式のΣの枠組み
		for (size_t k = 0; k < Idata.size(); ++k)
		{
			//Σの中身
			inv[i] += Idata[k] * std::exp(-imaginary * 2.0f * std::acos(-1.0f) * float(i * k) / (float)Idata.size());
		}
		inv[i].real(inv[i].real() / Idata.size());
	}
	
	return inv;
}

