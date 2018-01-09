/* tests for every ops */

#ifndef TESTS_H
#define TESTS_H

#include "ops.h"

bool test_all();

bool test_interpolation_factor_2();
bool test_decimation_factor_2();
bool test_convolution();
bool test_analyse_haar();
bool test_synthese_haar();
bool test_analyse_97();
bool test_synthese_97();
bool test_analyse_97_lifting();
bool test_synthese_97_lifting();

#endif
