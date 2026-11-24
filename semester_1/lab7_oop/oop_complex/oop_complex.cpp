#include "oop_complex.h"
#include <iostream>
#include <cmath>

Complex& Complex::operator = (const Complex& newVal){
    if(this != &newVal){
        a = newVal.a;
        b = newVal.b;
    }
    return *this;
}
bool Complex::operator == (const Complex& val){return (a == val.a) && (b == val.b);}
bool Complex::operator != (const Complex& val){return !(*this == val);}

Complex& Complex::operator + (){return *this;}
Complex Complex::operator + (const Complex& val) const {return Complex(a + val.a, b + val. b);}
Complex Complex::operator + (double val) const {return Complex(a + val, b);}
Complex Complex::operator += (const Complex& val){*this = *this + val; return *this;}
Complex Complex::operator += (double val){*this = *this + val; return *this;}

Complex Complex::operator - (){return Complex(-a, -b);}
Complex Complex::operator - (const Complex& val) const {return Complex(a - val.a, b - val.b);}
Complex Complex::operator - (double val) const {return Complex(a - val, b);}
Complex Complex::operator -= (const Complex& val){*this = *this - val; return *this;}
Complex Complex::operator -= (double val){*this = *this - val; return *this;}

Complex Complex::operator * (const Complex& val) const{
    return Complex(a * val.a - b * val.b,
                   a * val.b + b * val.a);
}
Complex Complex::operator * (double val) const {return Complex(a * val, b * val);}
Complex Complex::operator *= (const Complex& val){*this = *this * val; return *this;}
Complex Complex::operator *= (double val){*this = *this * val; return *this;}

Complex Complex::operator / (const Complex& val) const {
    return Complex((a * val.a + b * val.b) / (val.a * val.a + val.b * val.b),
                   (b * val.a - a * val.b) / (val.a * val.a + val.b * val.b));
}
Complex Complex::operator / (double val) const {return Complex(a / val, b / val);}
Complex Complex::operator /= (const Complex& val){*this = *this / val; return *this;}
Complex Complex::operator /= (double val){*this = *this / val; return *this;}

double Complex::Real() const {return a;}
double Complex::Imag() const {return b;}
double Complex::Abs() const {return std::sqrt(a * a + b * b);}

Complex operator + (double a, const Complex& val){return val + a;}
Complex operator - (double a, const Complex& val){return Complex(a - val.a, -val.b);}
Complex operator * (double a, const Complex& val){return val * a;}
Complex operator / (double a, const Complex& val){return Complex(a * val.a / (val.a * val.a + val.b * val.b),
                                                                 -a * val.b / (val.a * val.a + val.b * val.b));}

int main()
{

    return 0;
}
