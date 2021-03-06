/* Operations on a Buffer
*/

#ifndef OPS_H
#define OPS_H

#include "buffer.h"

Buffer interpolation_factor_2(const Buffer& b);
Buffer decimation_factor_2(const Buffer& b);
Buffer convolution(const Buffer& x, const Buffer& _h);
void analyse_haar(const Buffer& x, Buffer& approx_and_tail);
void synthese_haar(Buffer& x, const Buffer& approx_and_tail);
void analyse_97(const Buffer& x, Buffer& approx_and_tail);
void synthese_97(Buffer& x, const Buffer& approx_and_tail);
void analyse_97_lifting(Buffer& x);
void synthese_97_lifting(Buffer& x);
void amr(Buffer& x, unsigned niveau);
void iamr(Buffer& x, unsigned niveau);
void analyse2D_97(Buffer2D& m);
void synthese2D_97(Buffer2D& m);
void amr2D_97(Buffer2D& m, unsigned niveau);
void iamr2D_97(Buffer2D& m, unsigned niveau);

#endif
