/* Defines Buffer type.
*/
 
#ifndef BUFFER_H
#define BUFFER_H
 
#include <vector>
#include <string>
 
typedef std::vector<double> Buffer;

bool buffer_equal(const Buffer& a, const Buffer& b, double max_delta = 0.00001);
void print_buffer(const Buffer& b, unsigned display_max=8);
Buffer load_buffer_from_file(const std::string& file);
void write_buffer_to_file(const Buffer& b, std::string file);
Buffer make_buffer_ramp(unsigned size);
Buffer add_buffers(const Buffer& a, const Buffer& b);
unsigned amr_max_level(const Buffer& b);
double max_buffer(const Buffer& b);
double min_buffer(const Buffer& b);
double mean_buffer(const Buffer& b);

// stockage en lignes
// toutes les lignes doivent avoir la même taille.
struct Buffer2D {
    std::vector<Buffer> data;
    
    Buffer2D() {}
    Buffer2D(unsigned w, unsigned h, double value=0);
    
    bool equal(const Buffer2D& b) const;
    
    unsigned w() const { return !data.empty() ? data[0].size() : 0; }
    unsigned h() const { return data.size(); }
    Buffer2D transpose();
    Buffer2D extract(unsigned x, unsigned y, unsigned w, unsigned h);
    Buffer2D extract_bande(unsigned i, unsigned niveau);
    std::vector<double> debits_bandes(unsigned niveau, double debit_global);
    void overwrite(const Buffer2D& b, unsigned x, unsigned y);
    
    double min();
    double max();
    double moy();
    double var();
    
    bool read_img(std::string file);
    bool write_img(std::string file);
};

#endif // BUFFER_H
