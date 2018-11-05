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
	std::cout <<"p3 is " << p3 << '\n';
	Polynomial p4;
	std::cin >> p4;
	std::cout<<"p4 is " << p4<<'\n';
	Polynomial p5;
	
	std::cout << "Addition p3 + p4 : " << p3 + p4 << '\n';
	std::cout << "Addition p3+2 : " << p3 + 2 << '\n';
	
	
	std::cout << "Subtraction p3-p4 : " << p3-p4 << '\n';
	std::cout << "Subtraction p3-2 : " << p3 - 2 << '\n';
	Polynomial p6;
	std::cin >> p6;
	std::cout << p6 << '\n';
	std::cout << "Multiply p3 * p6: " << p3 * p6 << '\n';
	std::cout << p6.toString() << '\n';
	std::cout << "Multiply p3 * 2 : " << p3 * 2 << '\n';
	std::cout << "Modulo p3 % 2 " << p3 % 2 << '\n';
	std::cout << "Division p3/2 : " << p3 / 2 << '\n';
	p3 = p3 ^ 2;
	std::cout << "Power p3^2 : " << p3 << '\n';
	Polynomial p100, p101;
	std::cin >> p100;
	std::cout << "p100 is " << p100 << '\n';
	std::cin >> p101;
	std::cout << "p101 is " << p101 << '\n';
	if (p100 == p101)
	{
		std::cout << "p100 == p101" << '\n';
	}
	if (p100 != p101)
	{
		std::cout << " p100 != p101" << '\n';
	}
	if (3 == p100)
	{
		std::cout << "3 == p100" << '\n';
	}
	if (p100 == 3)
	{
		std::cout << "p100==3" << '\n';
	}

	if (p100 != 3)
	{
		std::cout << "p100!=3" << '\n';
	}

	if (3 != p100)
	{
		std::cout << "3!=p100" << '\n';
	}

	std::cout << "Polynomial value p100 in 2 : " << p100(2) << '\n';
	std::cout << "Monomial coefficient with grade 1: " << p100[1] << '\n';
	std::cout << "Negative polynomial -p100 : " << -p100 << '\n';
	p100 %= 2;
	std::cout << p100 << '\n';
	p100 /= 2;
	std::cout << p100 << '\n';
	p100 *= 2;
	std::cout << p100 << '\n';

	
	system("pause");
	return 0;
	

}

