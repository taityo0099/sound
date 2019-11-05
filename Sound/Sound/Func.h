#pragma once
#include<complex>
#include<vector>

namespace Func
{
	std::vector<std::complex<float>>DFT(const std::vector<float>& data);
	std::vector<std::complex<float>>IDFT(const std::vector<float>& Idata);

}