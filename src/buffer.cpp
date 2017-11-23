#include "buffer.h"

#include <iostream>

using namespace std;

bool buffer_equal(const Buffer& a, const Buffer& b) {
	if(a.size() != b.size()) return false;
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

void print_buffer(const Buffer& b, int display_max) {
	cout << "-- begin --" << endl;
	if(b.size() <= display_max) {
		for(int i = 0; i < b.size(); ++i) {
			cout << i << ": " << b[i] << endl;
		}
	} else {
		for(int i = 0; i < display_max/2; ++i) {
			cout << i << ": " << b[i] << endl;
		}
		cout << " ..." << endl;
		for(int i = b.size() - display_max/2; i < b.size(); ++i) {
			cout << i << ": " << b[i] << endl;
		}
	}
	cout << "-- end --" << endl;
}
