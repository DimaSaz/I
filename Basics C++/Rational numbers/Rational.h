#pragma once

#include <iostream>

class Rational
{
public:
	//Rational();
	//Rational(int num);
	//Rational(int num, int den);
	explicit Rational(int num_ = 0, int den_ = 1) : num(num_), den(den_)
	{
		Make();
	}
	void Make();
	void Reduction(); // Сокращение дробей
	int Evklid(int a, int b); // Алгоритм Евклида
	int GetInteger();
	double GetDouble();
	Rational const Rotate();
	// Операторы 
	friend std::ostream& operator<< (std::ostream&, Rational const&);
	friend std::istream& operator>> (std::istream&, Rational&);
	friend Rational const operator+ (Rational const&, Rational const&);
	friend Rational const operator+ (Rational const&, int);
	friend Rational const operator+= (Rational const&, Rational const&);
	friend Rational const operator- (Rational const&, Rational const&);
	friend Rational const operator- (Rational const&, int);
	friend Rational const operator-= (Rational const&, Rational const&);
	friend Rational const operator* (Rational const&, Rational const&);
	friend Rational const operator* (Rational const&, int);
	friend Rational const operator*= (Rational const&, Rational const&);
	friend Rational const operator/ (Rational const&, Rational const&);
	friend Rational const operator/ (Rational const&, int);
	friend Rational const operator/= (Rational const&, Rational const&);
	friend Rational const operator-- (Rational const&);
	friend Rational const operator++ (Rational const&);
	friend Rational const operator- (Rational const&);
	friend bool operator< (Rational const&, Rational const&);
	friend bool operator== (Rational const&, Rational const&);
	friend bool operator!= (Rational const&, Rational const&);
	friend bool operator> (Rational const&, Rational const&);
	friend bool operator<= (Rational const&, Rational const&);
	friend bool operator>= (Rational const&, Rational const&);
private:
	int num, den;
};