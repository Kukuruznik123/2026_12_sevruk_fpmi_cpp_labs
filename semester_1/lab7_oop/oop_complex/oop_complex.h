#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#pragma once

class Complex{
private:
    double a, b;
public:
    Complex() : a(0), b(0) {}
    Complex(double re) : a(re), b(0) {}
    Complex(double re, double im) : a(re), b(im) {}
    Complex(const Complex& newVal) : a(newVal.a), b(newVal.b) {}

    Complex& operator = (const Complex&);
    bool operator == (const Complex&);
    bool operator != (const Complex&);

    Complex& operator + ();
    Complex operator + (const Complex&) const;
    Complex operator + (double) const;
    friend Complex operator + (double, const Complex&);
    Complex operator += (const Complex&);
    Complex operator += (double);

    Complex operator - ();
    Complex operator - (const Complex&) const;
    Complex operator - (double) const;
    friend Complex operator - (double, const Complex&);
    Complex operator -= (const Complex&);
    Complex operator -= (double);

    Complex operator * (const Complex&) const;
    Complex operator * (double) const;
    friend Complex operator * (double, const Complex&);
    Complex operator *= (const Complex&);
    Complex operator *= (double);

    Complex operator / (const Complex&) const;
    Complex operator / (double) const;
    friend Complex operator / (double, const Complex&);
    Complex operator /= (const Complex&);
    Complex operator /= (double val);


    double Real() const;
    double Imag() const;
    double Abs() const;
};



#endif

