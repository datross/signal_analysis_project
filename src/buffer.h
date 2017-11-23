/* Defines Buffer type.
*/
 
#ifndef BUFFER_H
#define BUFFER_H
 
#include <vector>
 
typedef std::vector<double> Buffer;

bool buffer_equal(const Buffer& a, const Buffer& b);
void print_buffer(const Buffer& b, int display_max=8);

#endif // BUFFER_H
