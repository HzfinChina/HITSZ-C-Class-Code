#include<iostream>
using namespace std;

class Complex
{
    private:
        double real;
        double imag;
    public:
        Complex(double r = 0, double i = 0);
        Complex operator+(const Complex &b)
        {
            Complex ret;
            ret.real = real + b.real;
            ret.imag = imag + b.imag;
            return ret;
        }
        Complex operator-(const Complex &b)
        {
            Complex ret;
            ret.real = real - b.real;
            ret.imag = imag - b.imag;
            return ret;
        }
        Complex operator*(const Complex &b)
        {
            Complex ret;
            ret.real = real * b.real - imag * b.imag;
            ret.imag = imag * b.real + real * b.imag;
            return ret;
        }
        Complex operator/(const Complex &b)
        {
            Complex ret;
            ret.real = (real * b.real + imag * b.imag) / (b.real * b.real + b.imag * b.imag);
            ret.imag = (imag * b.real - real * b.imag) / (b.real * b.real + b.imag * b.imag);
            return ret;
        }
        friend void Print(const Complex &complex)
        {
            cout << noshowpos << complex.real << showpos<< complex.imag << "i" << endl;
        }
};
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

int main()
{
    Complex complex1(3,4), complex2(2,6);
    cout << "complex1 + complex2 =" << endl;
    Print(complex1 + complex2);
    cout << "complex1 - complex2 =" << endl;
    Print(complex1 - complex2);
    cout << "complex1 * complex2 =" << endl;
    Print(complex1 * complex2);
    cout << "complex1 / complex2 =" << endl;
    Print(complex1 / complex2);
}
