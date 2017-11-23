#include "tests.h"

#include <iostream>

using namespace std;

bool test_all() {
	bool result = test_interpolation_factor_2()
		&& test_decimation_factor_2();
		
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
	return false;
}
