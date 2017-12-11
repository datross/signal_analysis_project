#include "ops.h"

#define SQRT_2 1.41421356237

Buffer interpolation_factor_2(const Buffer& b) {
	Buffer buf(b.size() * 2);
	for(int i = 0; i < b.size(); ++i) {
		buf[2*i] = b[i];
	}
	return buf;
}

Buffer decimation_factor_2(const Buffer& b) {
	Buffer buf(b.size() / 2);
	for(int i = 0; i < buf.size(); ++i) {
		buf[i] = b[2*i];
	}
	return buf;
}

Buffer convolution(const Buffer& x, const Buffer& _h) {
	Buffer result(x.size() + _h.size() - 1);
    for(int n = 0; n < result.size(); ++n) {
        for(int k = 0; k < _h.size(); ++k) {
            int t = n - _h.size() + k + 1;
            if(t < 0 || t >= x.size()) continue;
            result[n] += x[t] * _h[_h.size() - k - 1];
        }
	}
    return result;
}

void analyse_haar(const Buffer& x, Buffer& approx_and_tail)
{
    const static Buffer _h0 = {1. / SQRT_2, 1. / SQRT_2, 0};
    const static Buffer _h1 = {1. / SQRT_2, -1. / SQRT_2, 0};
    
    Buffer approx = decimation_factor_2(convolution(x, _h0));
    Buffer tail = decimation_factor_2(convolution(x, _h1));
    
    approx_and_tail.clear();
    approx_and_tail.insert(approx_and_tail.end(), approx.begin(), approx.end());
    approx_and_tail.insert(approx_and_tail.end(), tail.begin(), tail.end());
}

void synthese_haar(Buffer& x, const Buffer& approx_and_tail)
{
    const static Buffer _g0 = {0., 1. / SQRT_2, 1. / SQRT_2};
    const static Buffer _g1 = {0., -1. / SQRT_2, 1. / SQRT_2};
    
    Buffer approx = convolution(interpolation_factor_2(approx_and_tail), _g0);
    Buffer tail = convolution(interpolation_factor_2(approx_and_tail), _g1);
    
    x = add_buffers(approx, tail);
}

