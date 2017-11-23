#include "ops.h"

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
	
	
}
