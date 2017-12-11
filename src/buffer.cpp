#include "buffer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <algorithm>

using namespace std;

bool buffer_equal(const Buffer& a, const Buffer& b) {
	if(a.size() != b.size()) return false;
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

void print_buffer(const Buffer& b, unsigned display_max) {
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

double str_to_double(const string& str) {
    stringstream ss(str);
    double d;
    ss >> d;
    return d;
}

Buffer load_buffer_from_file(const string& file)
{
    ifstream s(file, ifstream::in);
    if(!s) throw runtime_error("Cannot open file: " + file);
    Buffer b;
    string line;
    while(getline(s, line)) {
        b.push_back(str_to_double(line));
    }
    return b;
}

void write_buffer_to_file(const Buffer& b, std::string file)
{
    ofstream s(file, ifstream::out);
    if(!s) throw runtime_error("Cannot create file: " + file);
    for(auto it: b) {
        s << it << endl;
    }
}

Buffer make_buffer_ramp(unsigned int size)
{
    Buffer b(size);
    for(unsigned i = 0; i != size; ++i) {
        b[i] = i;
    }
    return b;
}

Buffer add_buffers(const Buffer& a, const Buffer& b)
{
    Buffer a_plus_b(min(a.size(), b.size()));
    for(unsigned i = 0; i < a_plus_b.size(); ++i) {
        a_plus_b[i] = a[i] + b[i];
    }
    return a_plus_b;
}


