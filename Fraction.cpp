#include <iostream>
#include <algorithm>
#include <string>
#include "Fraction.h"

using std::cout;
using std::cin;
using std::endl;
using std::to_string;

/*Ctor of Fraction*/
Fraction::Fraction(long num, long den)
{
	this->num = num;
	this->den = den;

	normalize();
	reduce();
}

/*function to normalize a negative fraction */
Fraction & Fraction::normalize()
{
	if (this->den < 0) {
		this->den = this->den * (-1);
		this->num = this->num * (-1);
	}
	return *this;
}

/*function to reduce a fraction */
Fraction & Fraction::reduce()
{

	/*Setting a flag to check whether num is negative*/
	bool flag = false;

	if (this->num < 0){
		this->num = this->num * (-1);
		flag = true;
	}
	
	/* if den<num*/
	if (this->den < this->num) {
		long i = this->den;
		while (i >= 1) {
			if (this->den % i == 0 && this->num % i == 0) {
				this->den = this->den / i;
				this->num = this->num / i;

				if (flag == true){
					this->num = this->num * (-1);
					flag = false;
				}
			}
			--i;
		}
	}

	/*if num<den*/
	if (this->num < this->den) {
		long i = this->num;

		while (i >= 1) {
			if (this->den % i == 0 && this->num % i == 0) {
				this->den = this->den / i;
				this->num = this->num / i;

				if (flag == true){
					this->num = this->num * (-1);
					flag = false;
				}
			}
			--i;
		}
	}
	
	return *this;
}

/*Getters and Setters*/
void Fraction::setNum(long i){
	this->num = i;
}
void Fraction::setDen(long i){
	this->den = i;
}

long Fraction::getNum() const{
	return this->num;
}

long Fraction::getDen() const{
	return this->den;
}

/*public functions: overloaded members; f for function objects and i for integer*/

/*f=i*/
Fraction & Fraction::operator=(const int & i){
	this->num = i;
	this->den = 1;	
	return(*this);
}

/*f+=i*/
Fraction & Fraction::operator+=(const int & i){
	this->num = this->num + (i*this->den);
	this->den = this->den;		
	return(*this);
}

/*f-=i*/
Fraction & Fraction::operator-=(const int & i){
	this->num = this->num - (i*this->den);
	this->den = this->den;	
	return(*this);
}

/*f*=i*/
Fraction & Fraction::operator*=(const int & i){
	this->num = this->num * i;
	this->den = this->den;
	reduce();	
	return(*this);
}

/*f/=i*/
Fraction & Fraction::operator/=(const int & i){
	this->num = this->num;
	this->den = this->den*i;
	reduce();	
	return(*this);
}


/*Binary Operations between function objects*/

/*f=f*/
Fraction & Fraction::operator=(const Fraction & f){
	this->num = f.num;
	this->den = f.den;	
	return(*this);
}

/*f+=f*/
Fraction & Fraction::operator+=(const Fraction & f){
	*this = (*this) + f;
	return(*this);
}

/*f-=f*/
Fraction & Fraction::operator-=(const Fraction & f){
	*this = (*this) - f;
	return(*this);
}

/*f*=f*/
Fraction & Fraction::operator*=(const Fraction & f){
	(*this) = (*this) * f;
	return(*this);

}

/*f/=f*/
Fraction & Fraction::operator/=(const Fraction & f){
	*this = (*this)/f;
	normalize();	
	return(*this);
}


/*Function objects operator()*/

/*f();*/
string Fraction::operator()() const{
	string sNum = to_string(this->num);
	string sDen = to_string(this->den);
	string str = sNum + "/" + sDen;
	return str;
}

/*makes function objects look like pointers*/
Fraction & Fraction::operator*(){
	return(*this);
}


/*subscript operator*/

/* returns num is s is top else den*/
long& Fraction::operator[](const string & s){
	if ((s.compare("top")) == 0){
		return this->num;
	}
	else if ((s.compare("bottom")) == 0){
		return this->den;
	}
}

const long& Fraction::operator[](const string & s) const{
	if ((s.compare("top")) == 0){
		return this->num;
	}
	else if ((s.compare("bottom")) == 0){
		return this->den;
	}
}

/* ++f*/
Fraction& Fraction:: operator++(){
	*this += 1; 
	return (*this);
}

/* --f */
Fraction& Fraction:: operator--(){
	*this-= 1; 
	return (*this);
}

/* f++ */
Fraction Fraction::operator++(int i){
	Fraction f2(this->num, this->den);
	*this+=1;
	return f2;
} 

/* f-- */
Fraction Fraction::operator--(int i){
	Fraction f2(this->num, this->den);
	*this-=1;
	return f2;
} 

/* +f */
Fraction Fraction::operator+()const{
	Fraction f2(this->num, this->den);
	f2.setNum(f2.getNum()*(+1));
	f2.setDen(f2.getDen()*(+1));
	return f2;
} 

 /* -f */
Fraction Fraction::operator-()const{
	Fraction f2(this->num, this->den);
	f2.setNum(f2.getNum()*(-1));
	return f2;	
}


/*Non-member functions*/

/*Arithmetic Operators*/


/* f3 = f1+f2 */
Fraction operator+(const Fraction & f1, const Fraction & f2){
	Fraction f3((f1.getNum()*f2.getDen()) + (f2.getNum()*f1.getDen()), f1.getDen()*f2.getDen() );
	return f3;
}

/* f3 = f1+i */
Fraction operator+(const Fraction & f1, const int & i){
	long a = f1.getNum() + (i*f1.getDen());
	Fraction f3(a, f1.getDen() );
	return f3;
}


/* f3=i+f1 */
Fraction operator+(const int & i, const Fraction & f1){
	Fraction f3 = f1 + i;
	return f3;
}


/* f3 =f1-f2 */
Fraction operator-(const Fraction &f1, const Fraction &f2){
	Fraction f3((f1.getNum()*f2.getDen()) - (f2.getNum()*f1.getDen()), f1.getDen()*f2.getDen());
	return f3;
}

/* f3= f1-i */
Fraction operator-(const Fraction &f1, const int &i){
	long a = f1.getNum() - (i*f1.getDen());
	Fraction f3(a,f1.getDen());
	return f3;
}

/* f3 = i-f1 */
Fraction operator-(const int & i, const Fraction & f1){
	long a = (i*f1.getDen())- f1.getNum();
	Fraction f3(a, f1.getDen() );
	return f3;
}


/* f3 = f1*f2 */
Fraction operator*(const Fraction &f1, const Fraction &f2){
	Fraction f3((f1.getNum()*f2.getNum()), f1.getDen()*f2.getDen());	
	return f3;
}

/* f3 = f1*i */
Fraction operator*(const Fraction &f1, const int &i){
	Fraction f3((f1.getNum()*i), f1.getDen());
	return f3;
}

/* f3=i*f1 */
Fraction operator*(const int &i, const Fraction &f1){
	Fraction f3((f1.getNum()*i), f1.getDen());
	return f3;
}

/* f3 =f1/f2 */
Fraction operator/(const Fraction &f1, const Fraction &f2){
	Fraction f3((f1.getNum()*f2.getDen()), (f1.getDen()*f2.getNum()));
	return f3;
}

/* f3 =f1/i */
Fraction operator/(const Fraction &f1, const int & i){
	Fraction f3((f1.getNum()), (f1.getDen()*i));
	return f3;
}

/* f3 =i/f1 */
Fraction operator/(const int &i, const Fraction &f1){
	Fraction f3((i*f1.getDen()), f1.getNum());
	return f3;
}


/* Relational Operations */
/* f1 == f2 */
bool operator==(const Fraction &f1, const Fraction &f2){
	return(f1.getNum() == f2.getNum() && f1.getDen() == f2.getDen());		
}

/* f == i */
bool operator==(const Fraction &f1, const int &i){
	return(f1.getNum() == i && f1.getDen() == 1);
}

/* i == f */
bool operator==(const int &i, const Fraction &f1){
	return(f1.getNum() == i && f1.getDen() == 1);
}

/* f != f */
bool operator!=(const Fraction &f1, const Fraction &f2){
	return(f1.getNum() != f2.getNum() || f1.getDen() != f2.getDen());
}

/* f != i */
bool operator!=(const Fraction &f1, const int &i){
	return(f1.getNum() != i || f1.getDen() != 1);
}

/* i != f */
bool operator!=(const int &i, const Fraction &f1){
	return(f1.getNum() != i || f1.getDen() != 1);
}

/* f < f */
bool operator<(const Fraction &f1, const Fraction &f2){
	return ((f1 - f2).getNum() < 0);
}

/* f < i */
bool operator<(const Fraction &f1, const int &i){
	return(f1 < Fraction(i,1));
}

/* i < f */
bool operator<(const int &i, const Fraction &f1){
	return (Fraction(i, 1) < f1);
}

/* f > f */
bool operator>(const Fraction &f1, const Fraction &f2){
	return ((f1 - f2).getNum() > 0);
}

/*f > i */
bool operator>(const Fraction &f1, const int &i){
	return((f1 - Fraction(i, 1)).getNum() > 0);
}

/* i > f */
bool operator>(const int &i, const Fraction &f1){
	return((Fraction(i, 1) - f1).getNum() > 0);
}

/* f <= f */
bool operator<=(const Fraction &f1, const Fraction &f2){
	return(f1 < f2 || f1 == f2);
}

/* f<= i */
bool operator<=(const Fraction &f1, const int &i){
	return(f1 < i || f1 == i);
}

/* i<= f */
bool operator<=(const int &i, const Fraction &f1){
	return(i < f1 || i == f1);
}

/* f >= f */
bool operator>=(const Fraction &f1, const Fraction &f2){
	return(f1 > f2 || f1 == f2);
}

/* f >- i */
bool operator>=(const Fraction &f1, const int &i){
	return(f1 > Fraction(i, 1) || f1 == i);
}

/* i >= f */
bool operator>=(const int &i, const Fraction &f1){
	return((Fraction(i, 1) > f1) || i == f1);
}

/*cin>>f*/
istream & operator>>(istream &in, Fraction &f){
	long temp;
	cout << "Enter numerator :";
	in >> temp;
	f.setNum(temp);
	cout << "Enter denominator :";
	in >> temp;
	f.setDen(temp);
	f.normalize();
	f.reduce();
	return in;
}


ostream& operator<<(ostream& out, const Fraction& f){
	out<<f()<<endl;
	return out;
}










