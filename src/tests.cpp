#include "tests.h"

#include <iostream>

using namespace std;

bool test_all() {
	bool result = test_interpolation_factor_2()
		&& test_decimation_factor_2()
		&& test_convolution();

	if(result) cout << "Tests succeeded." << endl;
	else cout << "One test failed." << endl;

	return result;
}

bool test_interpolation_factor_2() {
	cout << "Test interpolation factor 2" << endl;

	Buffer b = {1., 2., 3., 4.};
	Buffer i = interpolation_factor_2(b);
	Buffer i_expected = {1., 0., 2., 0., 3., 0., 4., 0.};

	print_buffer(b);
	print_buffer(i);

	return buffer_equal(i, i_expected);
}

bool test_decimation_factor_2() {
	cout << "Test decimation factor 2" << endl;

    Buffer b = {1., 2., 3., 4.};
    Buffer i = decimation_factor_2(b);
    Buffer i_expected = {1., 3.};

    print_buffer(b);
    print_buffer(i);

    return buffer_equal(i, i_expected);
}

bool test_convolution() {
    cout << "Test convolution" << endl;

    Buffer x = {1., 2., 3., 4.};
    Buffer _h = {1., 2.};
    Buffer conv = convolution(x, _h);
    Buffer expected = {1., 4., 7., 10., 8.};

    print_buffer(x);
    print_buffer(_h);
    print_buffer(conv);

    return buffer_equal(conv, expected);
}

bool test_analyse_haar()
{
    // TODO
    return false;
}


