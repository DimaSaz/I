#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include "Rational.h"


//Rational::Rational()
//{
//	this->num = 0;
//	this->den = 1;
//}

//Rational::Rational(int num)
//{
//	this->num = num;
//	this->den = 1;
//}

//Rational::Rational(int num, int den)
//{
//	this->num = num;
//	this->den = den;
//}

void Rational::Make()
{
	if (!den)
		throw std::invalid_argument("denominator should not be zero");
	if (((num >> (sizeof(num) * 8 - 1)) ^ (den >> (sizeof(den) * 8 - 1))) & 1)
		num = -std::abs(num);
	else
		num = std::abs(num);
	den = std::abs(den);
	Reduction(); // Включает сокращение дробей
}

void Rational::Reduction()
{
	int b = this->den;
	int a = this->num;
	int c = Evklid(a, b);
	this->den = b / c;
	this->num = a / c;
}

int Rational::Evklid(int a, int b)
{
	if (b == 0)
		return a;

	return Evklid(b, a % b);
}

int Rational::GetInteger()
{
	return (this->num / this->den);
}

double Rational::GetDouble()
{
	return (double(this->num) / double(this->den));
}

Rational const Rational::Rotate()
{
	return Rational(this->den, this->num);
}

std::ostream& operator<<(std::ostream& ost, Rational const& r)
{
	return ost << r.num << '/' << r.den;
}

std::istream& operator>>(std::istream& ist, Rational& r) // e.g. (5, -2)
{
	std::string s;
	std::getline(ist, s, ')');
	std::string::size_type ind;
	while ((ind = s.find_first_of("(,)")) != std::string::npos)
		s.replace(ind, 1, 1, ' ');
	std::istringstream iss(s);
	iss >> r.num >> r.den;
	r.Make();
	return ist;
}

Rational const operator+ (Rational const& lhs, Rational const& rhs)
{
	return Rational(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Rational const operator+(Rational const & lhs, int a)
{
	return Rational(lhs.num + (a * lhs.den), lhs.den);
}

Rational const operator+=(Rational const & lhs, Rational const & rhs)
{
	return Rational(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Rational const operator- (Rational const& lhs, Rational const& rhs)
{
	return lhs + Rational(-rhs.num, rhs.den);
}

Rational const operator-(Rational const & lhs, int a)
{
	return Rational(lhs.num - (a * lhs.den), lhs.den);
}

Rational const operator-= (Rational const& lhs, Rational const& rhs)
{
	return lhs + Rational(-rhs.num, rhs.den);
}

Rational const operator* (Rational const& lhs, Rational const& rhs)
{
	return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

Rational const operator*(Rational const & lhs, int a )
{
	return Rational(lhs.num * a, lhs.den);
}

Rational const operator*= (Rational const& lhs, Rational const& rhs)
{
	return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

Rational const operator/ (Rational const& lhs, Rational const& rhs)
{
	return Rational(rhs.den * lhs.num , rhs.num * lhs.den);
}

Rational const operator/(Rational const & lhs, int a)
{
	return Rational(lhs.num, lhs.den * a);
}

Rational const operator/= (Rational const& lhs, Rational const& rhs)
{
	return Rational(rhs.den * lhs.num, rhs.num * lhs.den);
}

Rational const operator--(Rational const & hs)
{
	return hs - Rational(hs.den, hs.den);
}

Rational const operator++(Rational const & hs)
{
	return  hs + Rational(hs.den, hs.den);
}

Rational const operator-(Rational const & hs)
{
	if (hs.den > 0 && hs.num > 0)
		return Rational(0 - hs.num, hs.den);
	else
		return Rational(std::abs(hs.num), std::abs(hs.den));
}

bool operator< (Rational const& lhs, Rational const& rhs)
{
	return double(lhs.num) / lhs.den < double(rhs.num) / rhs.den;
}

bool operator== (Rational const& lhs, Rational const& rhs)
{
	return !(lhs < rhs || rhs < lhs);
}

bool operator!=(Rational const & lhs, Rational const & rhs)
{
	return !(lhs == rhs);
}

bool operator> (Rational const& lhs, Rational const& rhs)
{
	return rhs < lhs;
}

bool operator<= (Rational const& lhs, Rational const& rhs)
{
	return !(rhs < lhs);
}

bool operator>= (Rational const& lhs, Rational const& rhs)
{
	return !(lhs < rhs);
}