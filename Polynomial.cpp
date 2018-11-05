#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include "Polynomial.h"


// Initialize constructor
// Creates a default polynomial p of the form p(x) = 0.0
Polynomial::Polynomial() : size(1), coefs(new double[1]) {
	coefs[0] = 0.0;
}


// Parametric constructor
// Given an array of coefficients C (and it's size N) creates a polynomial
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

//toString function.  Prints polynomial in string
std::string Polynomial::toString()
{
	std::string answer;
	for (int i = 0; i < size ; i++)
	{
		std::string c = std::to_string(coefs[i]);
		std::string d = std::to_string(i);
		if (coefs[i] > 0) {
			answer += c + '*' + 'X' + '^' + d + " + ";
		}
			if (coefs[i] == 0)
			{
				answer += ' ';
			}
	}
	answer.pop_back();
	
	answer.pop_back();
	return answer;

}

// Operator =
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


// Operator +=
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



// Operator *= 
Polynomial & Polynomial::operator*=(double rhs) {
	
	for (int i = 0; i < size; i++) {
		coefs[i] *= rhs;
	}
	return *this;
}

Polynomial & Polynomial::operator*=(const Polynomial & rhs)
{

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
	int newSize = (rhs.size > size) ? rhs.size : size;
	double *newCoef = new double[newSize];

	for (int i = 0; i < newSize; i++) {
		newCoef[i] = 0;
	}
	for (int i = 0; i < rhs.size; i++) {
		newCoef[i] -= rhs.coefs[i];
	}
	for (int i = 0; i < size; i++) {
		newCoef[i] += coefs[i];
	}
	delete[] coefs;
	coefs = newCoef;
	size = newSize;
	return *this;
	
}

Polynomial & Polynomial::operator-=(double rhs)
{
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
	for (int i = 0; i < size; i++) {
		coefs[i] /= rhs;
	}
	return *this;
}

Polynomial & Polynomial::operator%=(double rhs)
{
	for (int i = 0; i < size; i++)
	{
		coefs[i] = fmod(coefs[i],rhs);
	}
	return *this;
}

double & Polynomial::operator()(double rhs)
{
	double value = 0.0;

	for (int i = 0; i < size; i++)
	{
		if (coefs[i] != 0.0)
			value = value + coefs[i] * pow(rhs, i);
	}
	return value;
}

double & Polynomial::operator[](int rhs)
{
	for (int i = 0; i < size; i++)
	{
		if (i == rhs)
		{
			return coefs[rhs];
		}
	}
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
 

// Operator -
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

// Overload /
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

//Overload %

/*
Polynomial operator%(const Polynomial & lhs, const Polynomial & rhs)
{

}
*/

Polynomial operator%(double lhs, const Polynomial & rhs)
{
	Polynomial answer(rhs);
	answer %= lhs;
	return answer;
}

Polynomial operator%(const Polynomial & lhs, double rhs)
{
	Polynomial answer(lhs);
	answer %= rhs;
	return answer;
}
//Overload power
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

bool operator==(double lhs, const Polynomial & rhs)
{

	if (rhs.size != 1)
		return false;
	for (int i = 0; i < rhs.size; i++)
	{
		if (rhs.coefs[i] != lhs)
		{
			return false;
		}
	}
	return true;
}

bool operator==(const Polynomial & lhs, double rhs)
{

	if (lhs.size != 1)
		return false;
	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.coefs[i] != rhs)
		{
			return false;
		}
	}
	return true;
}

//Overload !=
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

bool operator!=(double lhs, const Polynomial & rhs)
{
	if (rhs.size != 1)
		return true;
	for (int i = 0; i < rhs.size; i++)
	{
		if (rhs.coefs[i] != lhs)
		{
			return true;
		}
	}
	return false;

}

bool operator!=(const Polynomial & lhs, double rhs)
{
	if (lhs.size != 1)
		return true;
	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.coefs[i] != rhs)
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
