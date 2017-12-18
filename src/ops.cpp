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
	Buffer result(x.size());
    for(int n = 0; n < result.size(); ++n) {
        for(int k = 0; k < _h.size(); ++k) {
            int t = n - _h.size()/2 + k;
            
            // mirror symetry
            if(t < 0) t = -t;
            if(t >= x.size()) t = 2 * x.size() - t - 2;
            
            result[n] += x[t] * _h[_h.size() - k - 1];
        }
	}
    return result;
}

void analyse_haar(const Buffer& x, Buffer& approx_and_tail) {
    const static Buffer _h0 = {1. / SQRT_2, 1. / SQRT_2, 0};
    const static Buffer _h1 = {1. / SQRT_2, -1. / SQRT_2, 0};
    
    Buffer approx = decimation_factor_2(convolution(x, _h0));
    Buffer tail = decimation_factor_2(convolution(x, _h1));
    
    approx_and_tail.clear();
    approx_and_tail.insert(approx_and_tail.end(), approx.begin(), approx.end());
    approx_and_tail.insert(approx_and_tail.end(), tail.begin(), tail.end());
}

void synthese_haar(Buffer& x, const Buffer& approx_and_tail) {
    const static Buffer _g0 = {0., 1. / SQRT_2, 1. / SQRT_2};
    const static Buffer _g1 = {0., -1. / SQRT_2, 1. / SQRT_2};
    
    Buffer approx = convolution(interpolation_factor_2(Buffer(approx_and_tail.begin(), 
                                                              approx_and_tail.begin() + approx_and_tail.size() / 2)), _g0);
    Buffer tail = convolution(interpolation_factor_2(Buffer(approx_and_tail.begin() + approx_and_tail.size() / 2, 
                                                            approx_and_tail.end())), _g1);
    
    x = add_buffers(approx, tail);
}

void analyse_97(const Buffer& x, Buffer& approx_and_tail) {
    static Buffer _h0(9);
    static Buffer _h1(9);
    
    _h0[0]= 0.037828455507;
    _h0[1]=-0.023849465019;
    _h0[2]=-0.110624404418;
    _h0[3]= 0.377402855613;
    _h0[4]= 0.852698679009;
    _h0[5]= 0.377402855613;
    _h0[6]=-0.110624404418;
    _h0[7]=-0.023849465019;
    _h0[8]= 0.037828455507;

    _h1[0]= 0.064538882629;
    _h1[1]=-0.040689417610;
    _h1[2]=-0.418092273222;
    _h1[3]= 0.788485616406;
    _h1[4]=-0.418092273222;
    _h1[5]=-0.040689417610;
    _h1[6]= 0.064538882629;
    _h1[7]= 0.000000000000;
    _h1[8]=-0.000000000000;
    
    Buffer approx = decimation_factor_2(convolution(x, _h0));
    Buffer tail = decimation_factor_2(convolution(x, _h1));
    
    approx_and_tail.clear();
    approx_and_tail.insert(approx_and_tail.end(), approx.begin(), approx.end());
    approx_and_tail.insert(approx_and_tail.end(), tail.begin(), tail.end());
}

void synthese_97(Buffer& x, const Buffer& approx_and_tail) {
    static Buffer _g0(7);
    static Buffer _g1(11);
    
    _g0[0]=-0.064538882629;
    _g0[1]=-0.040689417610;
    _g0[2]= 0.418092273222;
    _g0[3]= 0.788485616406;
    _g0[4]= 0.418092273222;
    _g0[5]=-0.040689417610;
    _g0[6]=-0.064538882629;

    
    _g1[0]= 0.000000000000;
    _g1[1]=-0.000000000000;
    _g1[2]= 0.037828455507;
    _g1[3]= 0.023849465019;
    _g1[4]=-0.110624404418;
    _g1[5]=-0.377402855613;
    _g1[6]= 0.852698679009;
    _g1[7]=-0.377402855613;
    _g1[8]=-0.110624404418;
    _g1[9]= 0.023849465019;
    _g1[10]=0.037828455507;
    
    Buffer approx = convolution(interpolation_factor_2(Buffer(approx_and_tail.begin(), 
                                                              approx_and_tail.begin() + approx_and_tail.size() / 2)), _g0);
    Buffer tail = convolution(interpolation_factor_2(Buffer(approx_and_tail.begin() + approx_and_tail.size() / 2, 
                                                            approx_and_tail.end())), _g1);
    
    x = add_buffers(approx, tail);
}



