#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
		friend ostream & operator<<(ostream &os,const ComplexNumber &c);
		ComplexNumber operator+(double con);
		ComplexNumber operator-(double con);
		friend ComplexNumber operator+(double con, const ComplexNumber &c);
		friend ComplexNumber operator-(double con, const ComplexNumber &c);
		ComplexNumber operator*(double con);
		ComplexNumber operator/(double con);
		friend ComplexNumber operator*(double con, const ComplexNumber &c);
		friend ComplexNumber operator/(double con, const ComplexNumber &c);
		bool operator==(double con);
		friend bool operator==(double con, const ComplexNumber &c);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here.
 
double ComplexNumber::abs(){
	return sqrt((real*real) + (imag*imag));
}

double ComplexNumber::angle(){
	return atan2(imag, real) * 180 / M_PI;
}

ComplexNumber ComplexNumber::operator-(double con){
	return ComplexNumber(real - con, imag);
}

ComplexNumber ComplexNumber::operator+(double con){
	return ComplexNumber(con + real, imag);
}

ComplexNumber operator-(double con, const ComplexNumber &c){
	return ComplexNumber(con - c.real, -c.imag);
}

ComplexNumber operator+(double con, const ComplexNumber &c){
	return ComplexNumber(con + c.real, c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	double r1 = ComplexNumber(real, imag).abs();
	double theta1 = ComplexNumber(real, imag).angle();

	double r2 = ComplexNumber(c.real, c.imag).abs();
	double theta2 = ComplexNumber(c.real, c.imag).angle();

	double r3 = r1 * r2;
	double theta3 = theta1 + theta2;

	theta3 = theta3*M_PI /180;

	return ComplexNumber(r3*cos(theta3), r3*sin(theta3));
}

ComplexNumber ComplexNumber::operator*(double con){
	return ComplexNumber(con * real, con * imag);
}

ComplexNumber ComplexNumber::operator/(double con){
	return ComplexNumber(real / con, imag / con);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double r1 = ComplexNumber(real, imag).abs();
	double theta1 = ComplexNumber(real, imag).angle();
	
	double r2 = ComplexNumber(c.real, c.imag).abs();
	double theta2 = ComplexNumber(c.real, c.imag).angle();
	
	double r3 = r1 / r2;
	double theta3 = theta1 - theta2;
	
	theta3 = theta3*M_PI /180;
	
	return ComplexNumber(r3*cos(theta3), r3*sin(theta3));
}

ComplexNumber operator*(double con, const ComplexNumber &c){
	return ComplexNumber(con * c.real, con * c.imag);
}

ComplexNumber operator/(double con, const ComplexNumber &c){
	double r = pow(ComplexNumber(c.real, c.imag).abs(),2);
	return ComplexNumber(con * c.real / r, con * (-c.imag) / r);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag) return true;
	else return false;
}

bool ComplexNumber::operator==(double con){
	if(con == real && imag == 0) return true;
	else return false;
}

bool operator==(double con, const ComplexNumber &c){
	if(con == c.real && c.imag == 0) return true;
	else return false;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
	if(c.real == 0 && c.imag == 0) return os << "0";
	else if(c.real == 0){
		return os << c.imag << "i";
	}
	else if(c.imag == 0){
		return os << c.real;
	}
	else{
		if(c.imag > 0)	return os << c.real << "+" << c.imag << "i";
		else return os << c.real << c.imag << "i";
	}	
}




int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}
