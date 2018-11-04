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
	
	
	
	
	
	
	
	/*
	
	//citire si scriere
	Polynomial p100;
	std::cin >> p100;
	std::cout << "p100 is " << '\n';
	std::cout << p100 << '\n';
	Polynomial p101;
	std::cin >> p101;
	std::cout << "p101 is " << p101 << '\n';
	
	//polinomul negat
	std::cout << "Negative polynomial is " << -p101 << '\n';
	
	//diferenta
	Polynomial p50;
	p50 = p100 - p101;
	std::cout << "p50 = " << p50 << '\n';
	
	//adunare
	Polynomial p3 = p1 + p2;
	p1 += p3;
	std::cout << "p1 += p3 is " << p1 << '\n' << "p2 is " << p2 << '\n';
	std::cout << "p3(p1+p2) is " << p3 << '\n';
	
	//diferenta
	Polynomial p = p1-p2;
	std::cout << "p(p2-p1) is " << p << '\n';
	
	double a4[] = { 3, 3, 3, 3, 3 };
	Polynomial p4(a4, 5);
	std::cout << p4 << '\n';
	p4 += Polynomial(8);
	std::cout << p4 << '\n';

	//inmultiri cu scalari
	Polynomial p5 = p4 * 0.5;
	Polynomial p6 = 4 * p5;
	std::cout << p5 << '\n' << p6 << '\n';

	///////->>>>>>>>>>>
    double x = 2;
	Polynomial p102;
	std::cin >> p102;
	p102 += x;
    std::cout << p102 << '\n' << x << '\n';
	std::cout <<"p102 + 2 " << p102 + 2 << '\n';
	std::cout <<"2+p102 "<< 2 + p102 << '\n';


	std::cout << "inmultire pol" << '\n';
	p102 *= p100;
	std::cout << p102 << '\n';
	std::cout << p102.toString() << '\n';
	p102 /= 2;
	std::cout << p102 << '\n';
	std::cout << p102 / 2 << '\n';
	std::cout << 2 / p102 << '\n';
	Polynomial p103;
	std::cin >> p103;
	p103 = p103 ^ 2;
	std::cout <<"Ridicare la puture "<< p103 << '\n';
	if (p4 == p4)
		std::cout << "p4 == p4" << '\n';
	if (p4 == p6)
		std::cout << "p4 == p6" << '\n';

	return 0;
	*/
}

