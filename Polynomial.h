#include <iostream>
#include <string>

class Polynomial {

	//friend bool operator==(const Polynomial & lhs, const Polynomial & rhs);

public:


	// constructors
	Polynomial();
	Polynomial(double coefficients[], int number);
	Polynomial(const Polynomial & rhs);
	explicit Polynomial(double const_term);

	// destructor
	~Polynomial();

	// named member functions
	int degree() const { return size - 1; }
	void print(std::ostream & out = std::cout) const;

	void show(std::istream & in);

	std::string toString();

	// assignment operators
	Polynomial & operator= (const Polynomial & rhs);
	Polynomial & operator+= (const Polynomial & rhs);
	Polynomial & operator+=(double rhs);
	Polynomial & operator*= (double rhs);
	Polynomial & operator*=(const Polynomial & rhs);
	Polynomial & operator-=(const Polynomial & rhs);
	Polynomial & operator-=(double rhs);
	Polynomial & operator/=(const Polynomial rhs);
	Polynomial & operator/=(double rhs);


	friend Polynomial operator-(const Polynomial &p);
	friend Polynomial operator+(const Polynomial &p);

	friend Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs);
	friend Polynomial operator+(double lhs, const Polynomial & rhs);
	friend Polynomial operator+(const Polynomial & lhs, double rhs);

	friend Polynomial operator-(const Polynomial & lhs, const Polynomial & rhs);
	friend Polynomial operator-(double lhs, const Polynomial & rhs);
	friend Polynomial operator-(Polynomial & lhs, double rhs);

	friend Polynomial operator*(const Polynomial & lhs, const Polynomial & rhs);
	friend Polynomial operator*(const Polynomial & lhs, double rhs);
	friend Polynomial operator*(double lhs, const Polynomial & rhs);

	friend Polynomial operator/(const Polynomial & lhs, const Polynomial & rhs);
	friend Polynomial operator/(double lhs, const Polynomial & rhs);
	friend Polynomial operator/(const Polynomial & lhs, double rhs);

	friend Polynomial operator^(const Polynomial & lhs, int rhs);

	friend bool operator==(const Polynomial & lhs, const Polynomial & rhs);
	friend bool operator!=(const Polynomial & lhs, const Polynomial & rhs);

	friend std::ostream & operator<<(std::ostream & out, const Polynomial & p);
	friend std::istream & operator>>(std::istream & in, Polynomial & p);


private:
	int size;       // size of the coefs array ( = degree + 1)
	double * coefs; // coefs will be an array
};