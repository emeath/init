#include <iostream>
#include <iomanip>
int main(){
	double n1,n2,media;
	std::cin >> n1 >> n2;
	media=(n1*3.5 + n2*7.5)/11;
	std::cout << std::fixed << std::setprecision(5) << "MEDIA = " << media << std::endl;
	return 0;
}
