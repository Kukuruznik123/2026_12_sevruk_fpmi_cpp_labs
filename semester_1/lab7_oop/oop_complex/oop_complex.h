#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#pragma once

#include <cmath>
#include <iostream>

class Complex{
private:
    double a, b;
public:
    Complex() : a(0), b(0) {}
    Complex(double re) : a(re), b(0) {}
    Complex(double re, double im) : a(re), b(im) {}
    Complex(const Complex& newVal) : a(newVal.a), b(newVal.b) {}

    Complex& operator = (const Complex& newVal){
        if(this != &newVal){
            a = newVal.a;
            b = newVal.b;
        }
        return *this;
    }
    bool operator == (const Complex& val){return (a == val.a) && (b == val.b);}
    bool operator != (const Complex& val){return !(*this == val);}

    Complex& operator + (){return *this;}
    Complex operator + (const Complex& val) const {return Complex(a + val.a, b + val. b);}
    Complex operator + (double val) const {return Complex(a + val, b);}
    friend Complex operator + (double, const Complex&);
    Complex operator += (const auto& val){*this = *this + val; return *this;}

    Complex operator - (){return Complex(-a, -b);}
    Complex operator - (const Complex& val) const {return Complex(a - val.a, b - val.b);}
    Complex operator - (double val) const {return Complex(a - val, b);}
    friend Complex operator - (double, const Complex&);
    Complex operator -= (const auto& val){*this = *this - val; return *this;}

    Complex operator * (const Complex& val) const{
        return Complex(a * val.a - b * val.b,
                       a * val.b + b * val.a);
    }
    Complex operator * (double val) const {return Complex(a * val, b * val);}
    friend Complex operator * (double, const Complex&);
    Complex operator *= (const auto& val){*this = *this * val; return *this;}

    Complex operator / (const Complex& val) const {
        return Complex((a * val.a + b * val.b) / (val.a * val.a + val.b * val.b),
                       (b * val.a - a * val.b) / (val.a * val.a + val.b * val.b));
    }
    Complex operator / (double val) const {return Complex(a / val, b / val);}
    friend Complex operator / (double, const Complex&);
    Complex operator /= (const auto& val){*this = *this / val; return *this;}


    double Real() const {return a;}
    double Imag() const {return b;}
    double Abs() const {return std::sqrt(a * a + b * b);}
};

Complex operator + (double a, const Complex& val){return val + a;}
Complex operator - (double a, const Complex& val){return Complex(a - val.a, -val.b);}
Complex operator * (double a, const Complex& val){return val * a;}
Complex operator / (double a, const Complex& val){return Complex(a * val.a / (val.a * val.a + val.b * val.b),
                                                                 -a * val.b / (val.a * val.a + val.b * val.b));}

#endif
