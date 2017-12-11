/* Defines Buffer type.
*/
 
#ifndef BUFFER_H
#define BUFFER_H
 
#include <vector>
#include <string>
 
typedef std::vector<double> Buffer;

bool buffer_equal(const Buffer& a, const Buffer& b);
void print_buffer(const Buffer& b, unsigned display_max=8);
Buffer load_buffer_from_file(const std::string& file);
void write_buffer_to_file(const Buffer& b, std::string file);
Buffer make_buffer_ramp(unsigned size);
Buffer add_buffers(const Buffer& a, const Buffer& b);

#endif // BUFFER_H
