#include "tests.h"

#include <iostream>

using namespace std;

bool test_all() {
	bool result = test_interpolation_factor_2()
		&& test_decimation_factor_2()
		&& test_convolution()
        && test_analyse_haar()
        && test_synthese_haar()
        && test_analyse_97()
        && test_synthese_97();

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
    Buffer _h = {1., 2., 3.};
    Buffer conv = convolution(x, _h);
    Buffer expected = {10., 10., 16., 20.};

    print_buffer(x);
    print_buffer(_h);
    print_buffer(conv);

    return buffer_equal(conv, expected);
}

bool test_analyse_haar()
{
    cout << "Test Haar analysis. Verify the resulting plots." << endl;
    
    Buffer ramp = make_buffer_ramp(256);
    Buffer leleccum = load_buffer_from_file("../data/leleccum.txt");
    
    Buffer approx_and_tail;
    
    analyse_haar(ramp, approx_and_tail);
    write_buffer_to_file(approx_and_tail, "../tests_results/haar_analysis_ramp.txt");
    analyse_haar(leleccum, approx_and_tail);
    write_buffer_to_file(approx_and_tail, "../tests_results/haar_analysis_leleccum.txt");
    
    return true;
}

bool test_synthese_haar()
{
    cout << "Test Haar synthesis. Verify the resulting plots." << endl;
    
    
    Buffer ramp = make_buffer_ramp(256);
    Buffer leleccum = load_buffer_from_file("../data/leleccum.txt");
    
    Buffer approx_and_tail;
    
    write_buffer_to_file(ramp, "../tests_results/ramp.txt");
    write_buffer_to_file(leleccum, "../tests_results/leleccum.txt");
    analyse_haar(ramp, approx_and_tail);
    synthese_haar(ramp, approx_and_tail);
    write_buffer_to_file(ramp, "../tests_results/haar_synthesis_ramp.txt");
    analyse_haar(leleccum, approx_and_tail);
    synthese_haar(leleccum, approx_and_tail);
    write_buffer_to_file(leleccum, "../tests_results/haar_synthesis_leleccum.txt");
    
    return true;
}

bool test_analyse_97()
{
    cout << "Test 97 analysis. Verify the resulting plots." << endl;
    
    Buffer ramp = make_buffer_ramp(256);
    Buffer leleccum = load_buffer_from_file("../data/leleccum.txt");
    
    Buffer approx_and_tail;
    
    analyse_97(ramp, approx_and_tail);
    write_buffer_to_file(approx_and_tail, "../tests_results/97_analysis_ramp.txt");
    analyse_97(leleccum, approx_and_tail);
    write_buffer_to_file(approx_and_tail, "../tests_results/97_analysis_leleccum.txt");
    
    return true;
}

bool test_synthese_97()
{
    cout << "Test 97 synthesis. Verify the resulting plots." << endl;
    
    
    Buffer ramp = make_buffer_ramp(256);
    Buffer leleccum = load_buffer_from_file("../data/leleccum.txt");
    
    Buffer approx_and_tail;
    
    // already written with haar test
    // write_buffer_to_file(ramp, "../tests_results/ramp.txt");
    // write_buffer_to_file(leleccum, "../tests_results/leleccum.txt");
    analyse_97(ramp, approx_and_tail);
    synthese_97(ramp, approx_and_tail);
    write_buffer_to_file(ramp, "../tests_results/97_synthesis_ramp.txt");
    analyse_97(leleccum, approx_and_tail);
    synthese_97(leleccum, approx_and_tail);
    write_buffer_to_file(leleccum, "../tests_results/97_synthesis_leleccum.txt");
    
    return true;
}



