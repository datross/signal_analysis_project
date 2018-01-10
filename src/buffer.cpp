#include "buffer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

bool buffer_equal(const Buffer& a, const Buffer& b, double max_delta) {
	if(a.size() != b.size()) return false;
	for(int i = 0; i < a.size(); ++i) {
		if(fabs(a[i] - b[i]) > max_delta) return false;
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

unsigned amr_max_level(const Buffer& b) {
    static float ln_2 = std::log(2.);
    return (unsigned) std::log(b.size() + 0.5) / ln_2; // +0.5 pour les erreurs de log
}

double max_buffer(const Buffer& b) {
    double max = -1 * numeric_limits<double>::infinity();
    for(auto & v : b) {
        if(v > max) max = v;
    }
    return max;
}

double min_buffer(const Buffer& b) {
    double min = numeric_limits<double>::infinity();
    for(auto & v : b) {
        if(v < min) min = v;
    }
    return min;
}

double mean_buffer(const Buffer& b) {
    double mean = 0;
    for(auto & v : b) {
        mean += v;
    }
    return mean / (double) b.size();
}

Buffer2D::Buffer2D(unsigned w, unsigned h, double value) 
    : data(h) {
    for(unsigned y = 0; y < h; ++y) {
        data[y] = Buffer(w, value);
    }
}


Buffer2D Buffer2D::transpose() {
    Buffer2D bt;
    bt.data = vector<Buffer>(w());
    
    for(unsigned x = 0; x < w(); ++x) {
        Buffer column(h());
        for(unsigned y = 0; y < h(); ++y) {
            column[y] = data[y][x];
        }
        bt.data[x] = column;
    }
    
    return bt;
}

bool Buffer2D::read_img(string file) {
    int x = 0, y = 0, n = 0;
    unsigned char *img = stbi_load(file.c_str(), &x, &y, &n, 1); // only grey
    if(!img) {
        cout << "Cannot load image in Buffer2D : " << file << endl;
        return false;
    }
    
    data = vector<Buffer>(y);
    for(unsigned i = 0; i < y; ++i) {
        Buffer line(x);
        for(unsigned j = 0; j < x; ++j) {
            line[j] = (double) img[i*x + j];
        }
        data[i] = line;
    }
    return true;
}

bool Buffer2D::write_img(std::string file) {
    vector<unsigned char> img(w() * h());
    for(unsigned y = 0; y < h(); ++y) {
        for(unsigned x = 0; x < w(); ++x) {
            unsigned char value_char = data[y][x];
            
            // clamping
            if(data[y][x] < 0) value_char = 0;
            else if(data[y][x] > 255) value_char = 255;
            
            img[y*w() + x] = value_char;
        }
    }
    if(!stbi_write_png(file.c_str(), w(), h(), 1, img.data(), w())) {
        cout << "Cannot write image file : " << file << endl;
        return false;
    }
    return true;
}

bool Buffer2D::equal(const Buffer2D& b) const {
    if(w() != b.w() || h() != b.h())
        return false;
    for(unsigned line = 0; line < b.h(); ++line) {
        if(!buffer_equal(data[line], b.data[line]))
            return false;
    }
    return true;
}

// pas de verif sur les valeurs.
Buffer2D Buffer2D::extract(unsigned x, unsigned y, unsigned _w, unsigned _h) {
    Buffer2D b(_w, _h);
    for(unsigned i = y; i < y+_h; ++i) {
        for(unsigned j = x; j < x+_w; ++j) {
            b.data[i-y][j-x] = data[i][j];
        }
    }
    return b;
}

// indiçage en ligne en commencant par les approximations
Buffer2D Buffer2D::extract_bande(unsigned i, unsigned niveau) {
    unsigned sauv_i = i;
    unsigned window_w = w() / pow(2, niveau - 1),
             window_h = h() / pow(2, niveau - 1);
    for(unsigned n = 0; n < niveau; ++n) {
        for(unsigned c = (i == sauv_i ? 0 : 1); c < 4; ++c) {
            unsigned x = (window_w / 2) * (c % 2);
            unsigned y = (window_h / 2) * (c / 2);
            if(i == 0) {
//                 cout << "    " << x << " " << y << " " << window_w / 2 << " " << window_h / 2 << endl;
                return extract(x, y, window_w / 2, window_h / 2);
            }
            --i;
        }
        window_w *= 2;
        window_h *= 2;
    }
    // i était trop grand
    throw runtime_error("Numero de bande trop grand : " + to_string(sauv_i));
}

vector<double> Buffer2D::debits_bandes(unsigned niveau, double debit_global) {
    vector<double> debits;
    vector<double> variances;
    vector<double> Ni;
    
    for(unsigned i = 0; i < 3*niveau+1; ++i) {
//         TODO
    }
    return debits;
}


void Buffer2D::overwrite(const Buffer2D& b, unsigned x, unsigned y) {
    for(unsigned i = y; i < y + b.h(); ++i) {
        for(unsigned j = x; j < x + b.w(); ++j) {
            data[i][j] = b.data[i-y][j-x];
        }
    }
}

double Buffer2D::min() {
    double min = numeric_limits<double>::infinity();
    for(unsigned y = 0; y < h(); ++y) {
        double tmp = min_buffer(data[y]);
        if(tmp < min) min = tmp;
    }
    return min;
}

double Buffer2D::max() {
    double max = -1 * numeric_limits<double>::infinity();
    for(unsigned y = 0; y < h(); ++y) {
        double tmp = min_buffer(data[y]);
        if(tmp > max) max = tmp;
    }
    return max;
}

double Buffer2D::moy() {
    double m = 0;
    for(auto& line : data)
        for(auto& v : line)
            m += v;
    return m / (double)(w() * h());
}

double Buffer2D::var() {
    double m = moy();
    double va = 0;
    for(auto& line : data)
        for(auto& v : line)
            va += (v - m) * (v - m);
    return va / (double)(w() * h());
}











