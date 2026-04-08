// Adding 2 complex numbers using friend function
#include <iostream>
using namespace std;

class Complex; // forward declaration
class D
{
public:
    void display(Complex &x);
};

class Complex
{
    float real, img;

public:
    Complex(); // default
    Complex(float i, float j);
    Complex(Complex &); // Copy constructor

    Complex operator+(Complex &x);
    // Friend Function
    friend Complex add(Complex &m, Complex &n);
    friend void D::display(Complex &x);
};
Complex Complex::operator+(Complex &x)
{
    Complex sum;
    sum.real + real + x.real;
    sum.img + img + x.img;
    return sum;
}
void D::display(Complex &m)
{
    cout << m.real << "+" << m.img << "i" << endl;
}
Complex::Complex()
{
    real = 0.0;
    img = 0.0;
}
Complex::Complex(float i, float j)
{
    real = i;
    img = j;
}
Complex::Complex(Complex &obj)
{
    real = obj.real;
    img = obj.img;
}

Complex add(Complex &m, Complex &n)
{
    Complex sum;
    sum.real = m.real + n.real;
    sum.img = m.img + n.img;
    return sum;
}

int main()
{
    Complex c1; // default constructor called
    Complex c2(9.3, 3.9);
    Complex c3(4.1, 5.4);
    Complex c4(c2);
    // c1 = add(c2, c4);
    c1 = c2.operator+(c3);
    // c1 = c4 + c2;

    D dis;
    dis.display(c1);
    dis.display(c4);
    dis.display(c1);

    return 0;
}