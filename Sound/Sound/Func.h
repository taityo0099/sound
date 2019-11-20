#pragma once
#include<complex>
#include<vector>

using Comp = std::vector<std::complex<float>>;

namespace Func
{
	Comp DFT(const std::vector<float>& data);
	Comp RDFT(const std::vector<float>& Idata);

}