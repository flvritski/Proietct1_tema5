#include "pch.h"
#include <iostream>
#include <string>
#include "Polynomial.h"


int main() {

	double a[] = { 1.1, 2.2, 3.3, 4.4 };
	Polynomial p1(a, 4);
	Polynomial p2(p1);
	
	std::cout << "p1 is " << p1 << '\n' << "p2 is " << p2 << '\n';
	
	
	
	Polynomial p3;
	std::cin >> p3;
	std::cout << p3 << '\n';
	Polynomial p4;
	std::cin >> p4;
	std::cout<<p4<<'\n';
	Polynomial p5;
	
	std::cout << "Adunare p3 + p4 : " << p3 + p4 << '\n';
	std::cout << "Adunare p3+2 : " << p3 + 2 << '\n';
	-p4;
	p5 = p3 + p4;
	std::cout << "Scadere p3-p4 : " << p5 << '\n';
	std::cout << "Scadere p3-2 : " << p3 - 2 << '\n';
	Polynomial p6;
	std::cin >> p6;
	std::cout << p6 << '\n';
	std::cout << "Inmultire p3 * p6: " << p3 * p6 << '\n';
	std::cout << p6.toString() << '\n';
	std::cout << "Inmultire p3 * 2 : " << p3 * 2 << '\n';
	std::cout << "Impartire p3/2 : " << p3 / 2 << '\n';
	p3 = p3 ^ 2;
	std::cout << "Ridicare p3^2 : " << p3 << '\n';
	Polynomial p100, p101;
	std::cin >> p100;
	std::cin >> p101;
	std::cout << "Valoarea polinomului in 2: " << p100(2) << '\n';
	std::cout << "Coeficientul monomului: " << p100[2] << '\n';
	if (p100 == p101)
	{
		std::cout << "p3 == p4" << '\n';
	}
	if (p100 != p101)
	{
		std::cout << " p3 != p6" << '\n';
	}
	system("pause");
	return 0;
	

}

