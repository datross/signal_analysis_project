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
        && test_synthese_97()
        && test_analyse_97_lifting()
        && test_synthese_97_lifting()
        && test_comparison_analysis()
        && test_amr_iamr()
        && test_analyse2D_97()
        && test_amr2D_iamr2D();

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

bool test_analyse_haar() {
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

bool test_synthese_haar() {
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

bool test_analyse_97() {
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

bool test_synthese_97() {
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

bool test_analyse_97_lifting() {
    cout << "Test 97 analysis lifting. Verify the resultings plots." << endl;
    
    Buffer leleccum = load_buffer_from_file("../data/leleccum.txt");
    
    analyse_97_lifting(leleccum);
    write_buffer_to_file(leleccum, "../tests_results/97_analysis_lifting_leleccum.txt");
    
    return true;
}

bool test_synthese_97_lifting() {
    cout << "Test 97 syntesis lifting. Verify the resulting plots." << endl;
    
    Buffer leleccum = load_buffer_from_file("../data/leleccum.txt");
    analyse_97_lifting(leleccum);
    synthese_97_lifting(leleccum);
    
    write_buffer_to_file(leleccum, "../tests_results/97_synthesis_lifting_leleccum.txt");
    
    return true;
}

// Comparaison de toutes les méthodes d'analyse.
// Elles sont toutes semblables (en particulier 97 et 97 lifting
// sont quasiment identiques).
// Cependant 97 lifting semble avoir une complexité légèrement inférieure 
// au 97 (facteur 2) et il peut se faire en place (même si mon implémentation 
// utilise un buffer temporaire pour la mise en forme, il doit y avoir un
// moyen d'éviter cela).
bool test_comparison_analysis() {
    cout << "Test comparison analysis Haar, 97, 97 lifting. Verify the resulting plots." << endl;
    
    Buffer test = load_buffer_from_file("../data/ligne_milieu_image.txt");
    
    // Haar
    Buffer approx_and_tail;
    analyse_haar(test, approx_and_tail);
    write_buffer_to_file(approx_and_tail, "../tests_results/haar_analysis_ligne_milieu.txt");
    
    // 97
    analyse_97(test, approx_and_tail);
    write_buffer_to_file(approx_and_tail, "../tests_results/97_analysis_ligne_milieu.txt");
    
    // 97 lifting
    analyse_97_lifting(test);
    write_buffer_to_file(test, "../tests_results/97_analysis_lifting_ligne_milieu.txt");
    
    return true;
}

// Si on réalise une AMR de niveau j, on obtient j+1 sous-bandes.
// Étude (résultats retranscrits) des sous-bandes du signal test :
// Niveau 2
//   0 - 128 |   57.32  232.78  394.73 
// 128 - 256 |  -43.89    1.42   47.09
// 256 - 512 |  -29.34    0.38   29.26
// Niveau 4
//   0 -  32 |  164.70  460.41  745.70 
//  32 -  64 | -123.62   -8.62   62.50 
//  64 - 128 |  -77.95   -5.44   79.05 
// 128 - 256 |  -43.89    1.42   47.09
// 256 - 512 |  -29.34    0.38   29.26
// 
// Observation :
// La moyenne tend vers 0 quand on avance dans les sous-bandes.
// La première sous-bande prend des valeurs plus grandes que le 
// nombre de niveau augmente.
// 
// L'AMR permet de séparer les niveaux de détails d'un signal,
// et potentiellement d'en compresser certains (on pourrait 
// diminuer la précision du codage pour les sous-bandes n'ayant
// pas une grande amplitude.
bool test_amr_iamr() {
    cout << "Test AMR and IAMR. Verify the resulting plots." << endl;
    
    Buffer test = load_buffer_from_file("../data/ligne_milieu_image.txt");
    
    Buffer tmp;
    
    // niveau 2
    cout << " - level 2" << endl;
    tmp = test;
    amr(tmp, 2);
    write_buffer_to_file(tmp, "../tests_results/amr_ligne_milieu_niveau_2.txt");
        // calcul des valeurs min, max, moyenne des sous-bandes
    for(unsigned window = tmp.size() / 4, prec = 0; window <= tmp.size(); window *= 2) {
        Buffer sous_bande(tmp.begin() + prec, tmp.begin() + window - 1);
        cout << "   max " << prec << "-" << window << " : " << max_buffer(sous_bande) << endl;
        cout << "   min " << prec << "-" << window << " : " << min_buffer(sous_bande) << endl;
        cout << "   moy " << prec << "-" << window << " : " << mean_buffer(sous_bande) << endl;
        prec = window;
    }
    iamr(tmp, 2);
    write_buffer_to_file(tmp, "../tests_results/iamr_ligne_milieu_niveau_2.txt");
    if(!buffer_equal(test, tmp)) return false;
    
    // niveau 4
    cout << " - level 4" << endl;
    tmp = test;
    amr(tmp, 4);
    write_buffer_to_file(tmp, "../tests_results/amr_ligne_milieu_niveau_4.txt");
        // calcul des valeurs min, max, moyenne des sous-bandes
    for(unsigned window = tmp.size() / 16, prec = 0; window <= tmp.size(); window *= 2) {
        Buffer sous_bande(tmp.begin() + prec, tmp.begin() + window - 1);
        cout << "   max " << prec << "-" << window << " : " << max_buffer(sous_bande) << endl;
        cout << "   min " << prec << "-" << window << " : " << min_buffer(sous_bande) << endl;
        cout << "   moy " << prec << "-" << window << " : " << mean_buffer(sous_bande) << endl;
        prec = window;
    }
    iamr(tmp, 4);
    write_buffer_to_file(tmp, "../tests_results/iamr_ligne_milieu_niveau_4.txt");
    if(!buffer_equal(test, tmp)) return false;
    
    // niveau max
    unsigned max_level = amr_max_level(test);
    cout << " - level max (" << max_level << ")" << endl;
    tmp = test;
    amr(tmp, max_level);
    write_buffer_to_file(tmp, "../tests_results/amr_ligne_milieu_niveau_" + to_string(max_level) + ".txt");
    iamr(tmp, max_level);
    write_buffer_to_file(tmp, "../tests_results/iamr_ligne_milieu_niveau_" + to_string(max_level) + ".txt");
    if(!buffer_equal(test, tmp)) return false;
    
    return true;
}

bool test_analyse2D_97() {
    cout << "Test analyse 2D 97. Verify the resulting plots." << endl;
    
    Buffer2D img;
    if(!img.read_img("../data/lena.bmp")) return false;
    analyse2D_97(img);
    if(!img.write_img("../tests_results/analyse2D_97_lena.png")) return false;

    return true;
}

// Résultats des moyennes et variances des sous-bandes.
// 0 | 988.06 127978.00
// 1 |  -0.95   3484.47
// 2 |  -0.00   1092.32
// 3 |  -0.33   1064.75
// 4 |   0.12    443.65
// 5 |  -0.01    170.15
// 6 |   0.07    115.93
// 7 |   0.05     42.93
// 8 |   0.00     17.22
// 9 |   0.00     17.22
// 
// La moyenne et la variance tendent vers 0 quand le niveau de détail augmente.
bool test_amr2D_iamr2D() {
    cout << "Test amr2D et iamr2D. Verify the resulting plots." << endl;
    
    Buffer2D lena;
    if(!lena.read_img("../data/lena.bmp")) return false;
    
    Buffer2D lena_amr = lena;
    amr2D_97(lena_amr, 3);
    
    // écriture de l'image avec modif pour voir qquchose
    Buffer2D tmp = lena_amr;
    // sauvegarde de l'approximation
    Buffer2D approx = tmp.extract(0, 0, tmp.w() / 8, tmp.h() / 8);
    // +127 partout
    for(auto & buf : tmp.data)
        for(auto & v : buf)
            v += 127.;
    // calcul des coeffs pour l'approx
    double min = approx.min(), max = approx.max();
    // réajustement de l'approx
    for(auto & buf : approx.data)
        for(auto & v : buf)
            v = (v - min) * (255. / (max - min));
    // remplacement de approx dans tmp
    tmp.overwrite(approx, 0, 0);
    tmp.write_img("../tests_results/amr2D_lena.png");
    
    // Calcul des moyennes et variances des sous-bandes.
    for(unsigned i = 0; i < 11; ++i) {
        auto bande = lena_amr.extract_bande(i, 3);
        cout << "  sous-bande " << i << " " << bande.moy() << " " << bande.var() << endl; 
    }
    
    iamr2D_97(lena_amr, 3);
    return lena_amr.equal(lena);
}







