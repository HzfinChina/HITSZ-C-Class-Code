#include <iostream>
using namespace std;
class Complex 
{
    private:
        double real, imag;
    public:
        Complex(double r = 0, double i = 0){
            real = r;
            imag = i;
        }
        Complex operator+(Complex b)
        {
            Complex ret(real + b.real, imag + b.imag);
            return ret;
        }
        Complex operator+(double d)
        {
            Complex ret(real + d, imag);
            return ret;
        }
        friend void Print(const Complex &complex)
        {
            cout << noshowpos << complex.real << showpos<< complex.imag << "i" << endl;
        }
        inline operator double(){
            return real;
        }
};

int main()
{
    double a = 3.1;
    Complex complex1(2.1,4.5);
    double d1 = double(complex1) + a;
    cout << "double of a + complex1:" << endl;
    cout << d1 << endl;
    cout << "complex of a + complex1:" << endl;
    Print(complex1 + a);

}
