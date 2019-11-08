#pragma once
#include<complex>
#include<vector>

namespace Func
{
	std::vector<std::complex<float>>DFT(const std::vector<float>& data);
	std::vector<std::complex<float>>RDFT(const std::vector<float>& Idata);

}