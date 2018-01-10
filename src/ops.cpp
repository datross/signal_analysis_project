#include "ops.h"

#include <algorithm>
#include <cmath>

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

unsigned mirror_index(const Buffer& b, int index) {
    if(index < 0)
        return -1 * index;
    else if(index >= b.size())
        return 2 * b.size() - index - 2;
    else
        return index;
}

void analyse_97_lifting(Buffer& x) {    
    // Prediction 1
    #define A -1.586134342
    for(unsigned i = 1; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Mise à jour 1
    #define A -0.05298011854
    for(unsigned i = 0; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Prediction 2
    #define A 0.8829110762
    for(unsigned i = 1; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Mise à jour 2
    #define A 0.4435068522
    for(unsigned i = 0; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Mise à l'échelle
    #define A (1./1.149604398)
    for(unsigned i = 0; i < x.size(); i += 2) {
        x[mirror_index(x, i)] /= A;
        x[mirror_index(x, i+1)] *= A;
    }
    // Mise en forme
    unsigned moitie = x.size() / 2;
    Buffer tmp(moitie);
    for(unsigned i = 0; i < moitie; ++i) {
        tmp[i] = x[mirror_index(x, 2*i+1)];
        x[mirror_index(x, i)] = x[mirror_index(x, 2*i)];
    }
    for(unsigned i = 0; i < moitie; ++i) {
        x[mirror_index(x, i+moitie)] = tmp[i];
    }
}

void synthese_97_lifting(Buffer& x) {
    // Mise en forme
    unsigned moitie = x.size() / 2;
    Buffer tmp(moitie); // contient les indices pairs
    for(unsigned i = 0; i < moitie; ++i) {
        tmp[i] = x[mirror_index(x, i)];
    }
    for(unsigned i = 0; i < moitie; ++i) {
        x[2*i] = tmp[i];
        x[2*i+1] = x[i+moitie];
    }
    // Mise à l'échelle
    #define A 1.149604398
    for(unsigned i = 0; i < x.size(); i += 2) {
        x[mirror_index(x, i)] /= A;
        x[mirror_index(x, i+1)] *= A;
    }
    // Mise à jour 2
    #define A -0.4435068522
    for(unsigned i = 0; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Prediction 2
    #define A -0.8829110762
    for(unsigned i = 1; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Mise à jour 1
    #define A 0.05298011854
    for(unsigned i = 0; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
    // Prediction 1
    #define A 1.586134342
    for(unsigned i = 1; i < x.size(); i += 2)
        x[mirror_index(x, i)] += A * (x[mirror_index(x, i-1)] + x[mirror_index(x, i+1)]);
}

void amr(Buffer& x, unsigned niveau) {
    Buffer tmp;
    unsigned analyse_window = x.size();
    for(unsigned i = 0; i < niveau; ++i) {
        tmp = Buffer(x.begin(), x.begin() + analyse_window);
        analyse_97_lifting(tmp);
        std::copy(tmp.begin(), tmp.end(), x.begin());
        analyse_window /= 2;
    }
}

void iamr(Buffer& x, unsigned niveau) {
    Buffer tmp;
    unsigned analyse_window = x.size() / (std::pow(2, niveau-1));
    for(unsigned i = 0; i < niveau; ++i) {
        tmp = Buffer(x.begin(), x.begin() + analyse_window);
        synthese_97_lifting(tmp);
        std::copy(tmp.begin(), tmp.end(), x.begin());
        analyse_window *= 2;
    }
}

void analyse2D_97(Buffer2D& m) {
    // computes ml
    for(unsigned y = 0; y < m.h(); ++y) {
        analyse_97_lifting(m.data[y]);
    }
    // computes md
    m = m.transpose();
    for(unsigned y = 0; y < m.h(); ++y) {
        analyse_97_lifting(m.data[y]);
    }
    m = m.transpose();
}

void synthese2D_97(Buffer2D& m) {
    // computes md
    m = m.transpose();
    for(unsigned y = 0; y < m.h(); ++y) {
        synthese_97_lifting(m.data[y]);
    }
    m = m.transpose();
    // computes ml
    for(unsigned y = 0; y < m.h(); ++y) {
        synthese_97_lifting(m.data[y]);
    }
}

void amr2D_97(Buffer2D& m, unsigned niveau) {
    Buffer2D tmp;
    unsigned w_window = m.w(),
             h_window = m.h();
    for(unsigned i = 0; i < niveau; ++i) {
        tmp = m.extract(0, 0, w_window, h_window);
        analyse2D_97(tmp);
        m.overwrite(tmp, 0, 0);
        w_window /= 2;
        h_window /= 2;
    }
}

void iamr2D_97(Buffer2D& m, unsigned niveau) {
    Buffer2D tmp;
    unsigned w_window = m.w() / pow(2, niveau - 1),
             h_window = m.h() / pow(2, niveau - 1);
    for(unsigned i = 0; i < niveau; ++i) {
        tmp = m.extract(0, 0, w_window, h_window);
        synthese2D_97(tmp);
        m.overwrite(tmp, 0, 0);
        w_window *= 2;
        h_window *= 2;
    }
}








