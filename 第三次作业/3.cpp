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
            Complex ret(real + b.real, imag + b.imag);
            return ret;
        }
        Complex operator+(const double &b)
        {
            Complex ret(real+b, imag);
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
    Complex complex1(3,2), complex2(4,-3);
    int intnum = 3;
    cout << "(3+2i) + (4-3i)" << endl;
    Print(complex1 + complex2);
    cout << "(3+2i) + 3" << endl;
    Print(complex1 + intnum);
}
