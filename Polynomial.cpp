#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include "Polynomial.h"


// Constructor initializare
// Creates a default polynomial p of the form p(x) = 0.0
Polynomial::Polynomial() : size(1), coefs(new double[1]) {
	coefs[0] = 0.0;
}


// Constructor parametrizare
// Given an array of coefficients C (and it's size N) creates a polynomial
// p(x) = C[N-1]x^(N-1) + ... + C[2]x^2 + C[1]x + C[0] 
Polynomial::Polynomial(double coefficients[], int number) :
	size(number), coefs(new double[number]) {
	for (int i = 0; i < size; i++) {
		coefs[i] = coefficients[i];
	}
}


// Copy constructor
// Creates a polynomial from the given polynomial
Polynomial::Polynomial(const Polynomial & rhs) :
	size(rhs.size), coefs(new double[rhs.size]) {
	for (int i = 0; i < size; i++) {
		coefs[i] = rhs.coefs[i];
	}
}


// Constructor
// Given a constant term A, creates the polynomial p(x) = A
Polynomial::Polynomial(double const_term) : size(1), coefs(new double[1]) {
	coefs[0] = const_term;
}


// Destructor
Polynomial::~Polynomial() {
	delete[] coefs;
}


// Prints the polynomial to the given ostream.  If no ostream is given,
// the polynomial is printed to cout
void Polynomial::print(std::ostream & out) const {
	if (size == 0) {
		return;
	}

	for (int i = size - 1; i > 0; i--)
		out << coefs[i] << "x^" << i << " + ";
	out << coefs[0];
}

void Polynomial::show(std::istream & in)
{
	std::cout << "Enter the degree of polynomial: ";
	in >> size;
	delete[] coefs;
	coefs = new double[size];
	
	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << "Enter the coeff for x^" << i << " : ";
		in >> coefs[i];
	}
}


std::string Polynomial::toString()
{
	std::string answer;
	for (int i = 0; i < size ; i++)
	{
		std::string c = std::to_string(coefs[i]);
		std::string d = std::to_string(i);
		answer += c + '*' + 'X' + '^' + d + " + ";
	
	}
	answer.pop_back();
	
	answer.pop_back();
	return answer;

}

// Overload assignment =
Polynomial & Polynomial::operator=(const Polynomial & rhs) {
	if (this == &rhs) {
		return *this;
	}

	else {
		delete[] coefs;
		coefs = new double[rhs.size];
		size = rhs.size;
		for (int i = 0; i < size; i++) {
			coefs[i] = rhs.coefs[i];
		}
	}
	return *this;
}


// Overload assignment +=
Polynomial & Polynomial::operator+=(const Polynomial & rhs) {
	int newSize = (rhs.size > size) ? rhs.size : size;
	double *newCoef = new double[newSize];

	for (int i = 0; i < newSize; i++) {
		newCoef[i] = 0;
	}
	for (int i = 0; i < rhs.size; i++) {
		newCoef[i] += rhs.coefs[i];
	}
	for (int i = 0; i < size; i++) {
		newCoef[i] += coefs[i];
	}
	delete[] coefs;
	coefs = newCoef;
	size = newSize;
	return *this;
}

Polynomial & Polynomial::operator+=(double rhs)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			 coefs[i] += rhs;
		}
	}
	return *this;
	
}



// Overload assignment *= so it supports scalar multiplication
Polynomial & Polynomial::operator*=(double rhs) {
	
	for (int i = 0; i < size; i++) {
		coefs[i] *= rhs;
	}
	return *this;
}

Polynomial & Polynomial::operator*=(const Polynomial & rhs)
{
	// TODO: insert return statement here

	int newSize = rhs.size + size - 1;
	double *newCoef = new double[newSize];

	for (int i = 0; i < newSize; i++) 
		newCoef[i] = 0;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rhs.size; j++)

			newCoef[i + j] += coefs[i] * rhs.coefs[j];
	}

		delete[] coefs;
		coefs = newCoef;
		size = newSize;
		return *this;
}

Polynomial & Polynomial::operator-=(const Polynomial & rhs)
{
	int newSize = (rhs.size < size) ? rhs.size : size;
	double *newCoef = new double[newSize];

	for (int i = 0; i < newSize; i++) {
		newCoef[i] = 0;
	}
	for (int i = 0; i < rhs.size; i++) {
		newCoef[i] -= rhs.coefs[i];
	}
	for (int i = 0; i < size; i++) {
		newCoef[i] -= coefs[i];
	}
	delete[] coefs;
	coefs = newCoef;
	size = newSize;
	return *this;
}

Polynomial & Polynomial::operator-=(double rhs)
{
	// TODO: insert return statement here
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			coefs[i] -= rhs;
		}
	}
	return *this;
}
/*
Polynomial & Polynomial::operator/=(const Polynomial rhs)
{
	// TODO: insert return statement here

}
*/
Polynomial & Polynomial::operator/=(double rhs)
{
	// TODO: insert return statement here
	for (int i = 0; i < size; i++) {
		coefs[i] /= rhs;
	}
	return *this;
}


//Operator +
Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs)
{
	Polynomial answer(lhs);
	answer += rhs;
	return answer;
}

Polynomial operator+(const Polynomial & lhs, double rhs)
{
	Polynomial answer(lhs);
	answer += rhs;
	return answer;
}

Polynomial operator+(double lhs, const Polynomial & rhs) {
	Polynomial answer(rhs);
	answer += lhs;
	return answer;
}
 


Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs)
{
	Polynomial answer(lhs);
	answer -= rhs;
	return answer;
}

Polynomial operator-(double lhs, const Polynomial & rhs)
{
	Polynomial answer(rhs);
	answer -= lhs;
	return answer;
}

Polynomial operator-(Polynomial & lhs, double rhs)
{
	Polynomial answer(lhs);
	answer -= rhs;
	return answer;

}

Polynomial operator*(const Polynomial & lhs, const Polynomial & rhs)
{
	Polynomial answer(lhs);
	answer *= rhs;
	return answer;
}

//Operator *
Polynomial operator*(const Polynomial & lhs, double rhs)
{
	Polynomial answer(lhs);
	answer *= rhs;
	return answer;
}

//Overload *
Polynomial operator*(double lhs, const Polynomial & rhs)
{
	Polynomial answer(rhs);
	answer *= lhs;
	return answer;
}

Polynomial operator/(double lhs, const Polynomial & rhs)
{
	Polynomial answer(rhs);
	answer /= lhs;
	return answer;
}

Polynomial operator/(const Polynomial & lhs, double rhs)
{
	Polynomial answer(lhs);
	answer /= rhs;
	return answer;
}


Polynomial operator^(const Polynomial & lhs, int rhs)
{
	Polynomial answer(lhs);
	Polynomial bnswer = answer;
	int i = 1;
	while (i < rhs)
	{
		answer = answer * bnswer;
		i++;
	}
	return answer;

}


//Negative
Polynomial operator-(const Polynomial &p)
{
	for (int i = 0; i < p.size; i++)
	{
		p.coefs[i] *= (-1);
	}
	return p;
}
// Positive
Polynomial operator+(const Polynomial &p)
{
	return p;
}
// Overload ==
bool operator==(const Polynomial & lhs, const Polynomial & rhs) {
	if (lhs.size != rhs.size) {
		return false;
	}

	for (int i = 0; i < lhs.size; i++) {
		if (lhs.coefs[i] != rhs.coefs[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const Polynomial & lhs, const Polynomial & rhs)
{
	if (lhs.size != rhs.size)
	{
		return true;
	}
	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.coefs[i] != rhs.coefs[i])
		{
			return true;
		}
	}
	return false;
}



// Overload << for output
std::ostream & operator<<(std::ostream & out, const Polynomial & p) {
	p.print(out);
	return out;
}


std::istream & operator>>(std::istream & in, Polynomial & p) {
	p.show(in);
	return in;

}