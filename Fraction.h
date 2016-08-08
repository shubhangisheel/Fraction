#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>

using std::string;
using std::ostream;
using std::istream;

/*class Fraction begins*/
class Fraction{

	/*private data members: num=numerator; den=denominator*/
private: long num;
		 long den;

		 /*private functions to be applied to all fractions : reduce and normalise*/
public: Fraction& normalize();
		 Fraction& reduce();

public:

	/*Constructor with default values*/
	Fraction(long num = 0, long den = 1);

	/*Getters and Setters*/
	void setNum(long);
	void setDen(long);
	long getNum() const;
	long getDen() const;

	/*public functions: overloaded members; f for function objects and i for integer*/

	Fraction & operator=(const int &);/*f=i*/
	Fraction & operator+=(const int &);/*f+=i*/
	Fraction & operator-=(const int &);/*f-=i*/
	Fraction & operator*=(const int &);/*f*=i*/
	Fraction & operator/=(const int &);/*f/=i*/

	/*Binary Operations between function objects*/

	Fraction & operator=(const Fraction &);/*f=f*/
	Fraction & operator+=(const Fraction &);/*f+=f*/
	Fraction & operator-=(const Fraction &);/*f-=f*/
	Fraction & operator*=(const Fraction &);/*f*=f*/
	Fraction & operator/=(const Fraction &);/*f/=f*/

	/*Unary Operations between function objects*/
	Fraction & operator++();/* ++f */
	Fraction & operator--();/* --f */

	/*Function objects operator()*/
	string operator()() const; /*f();*/
	Fraction & operator*(); /*makes function objects look like pointers*/

	/*subscript operator*/
	long & operator[](const string &);
	const long & operator[](const string &) const; 


	Fraction operator+()const; /* +f */
	Fraction operator-()const; /* -f */

	Fraction operator++(int); /* f++ */
	Fraction operator--(int); /* f-- */

};
/*class Fraction ends*/

/*Non-member functions*/

/*Arithmetic Operators*/

Fraction operator+(const Fraction &, const Fraction &); /* f+f */
Fraction operator+(const Fraction &, const int &); /* f+i */
Fraction operator+(const int &, const Fraction &); /* i+f */

Fraction operator-(const Fraction &, const Fraction &); /* f-f */
Fraction operator-(const Fraction &, const int &); /* f-i */
Fraction operator-(const int &, const Fraction &); /* i-f */

Fraction operator*(const Fraction &, const Fraction &); /* f*f */
Fraction operator*(const Fraction &, const int &); /* f*i */
Fraction operator*(const int &, const Fraction &); /* i*f */

Fraction operator/(const Fraction &, const Fraction &); /* f/f */
Fraction operator/(const Fraction &, const int &); /* f/i */
Fraction operator/(const int &, const Fraction &); /* i/f */

/* Relational Operations */

bool operator==(const Fraction &, const Fraction &); /* f == f */
bool operator==(const Fraction &, const int &); /* f == i */
bool operator==(const int &, const Fraction &); /* i == f */

bool operator!=(const Fraction &, const Fraction &); /* f != f */
bool operator!=(const Fraction &, const int &); /* f != i */
bool operator!=(const int &, const Fraction &); /* i != f */

bool operator<(const Fraction &, const Fraction &); /* f < f */
bool operator<(const Fraction &, const int &); /* f < i */
bool operator<(const int &, const Fraction &); /* i < f */

bool operator>(const Fraction &, const Fraction &); /* f > f */
bool operator>(const Fraction &, const int &); /* f > i */
bool operator>(const int &, const Fraction &); /* i > f */

bool operator<=(const Fraction &, const Fraction &); /* f <= f */
bool operator<=(const Fraction &, const int &); /* f<= i */
bool operator<=(const int &, const Fraction &); /* i<= f */

bool operator>=(const Fraction &, const Fraction &); /* f >= f */
bool operator>=(const Fraction &, const int &); /* f >- i */
bool operator>=(const int &, const Fraction &); /* i >= f */

/*output and input stream operators*/

ostream & operator<<(ostream &, const Fraction &); /* cout<<f */
istream & operator>>(istream &, Fraction &); /*cin>>f*/

#endif