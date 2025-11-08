/*
 * stderr -> std::cerr
 * atof   -> std::stod
 * */

#include <iostream>
#include <iomanip> // formatar precisao na impressao
#include <string>

int main (int argc, char* argv[]) {
	double A, B, C;
	if(argc > 1) {
		if(argc < 4) {
			// redirect to file ./a.out ... 2>error.txt
			std::cerr << "Usage: " << argv[0] << " A B C" << std::endl;
			return 1;
		}
		A = std::stod(argv[1]);
		B = std::stod(argv[2]);
		C = std::stod(argv[3]);
	} else {
		std::cin >> A >> B >> C;
	}
	double media = (A*2 + B*3 + C*5) / 10.0;
	std::cout << "MEDIA = " 
		<< std::fixed << std::setprecision(1)
		<< media << std::endl;
	return 0;
}
