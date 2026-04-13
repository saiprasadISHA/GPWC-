#include <iostream>
using namespace std;
const int size220 = 3;

class Vector
{
public:
    int v[size220];

public:
    Vector();
    Vector(int *x);
    friend Vector operator*(int a, Vector &b);
    friend Vector operator*(Vector &b, int a);
    friend istream &operator>>(istream &, Vector &);
    friend ostream &operator<<(ostream &, Vector &);
};

Vector::Vector()
{
    for (int i = 0; i < size220; i++)
    {
        v[i] = 0;
    }
}

Vector::Vector(int *x)
{
    for (int i = 0; i < size220; i++)
    {
        v[i] = x[i];
    }
}

Vector operator*(int a, Vector &b) // Frnd 1
{
    Vector c;
    for (int i = 0; i < size220; i++)
    {
        c.v[i] = a * b.v[i];
    }
    return c;
}

Vector operator*(Vector &b, int a) // Frnd 2
{
    Vector c;
    for (int i = 0; i < size220; i++)
    {
        c.v[i] = b.v[i] * a;
    }
    return c;
}

istream &operator>>(istream &din, Vector &b) // Frnd 3
{
    for (int i = 0; i < size220; i++)
    {
        din >> b.v[i];
    }
    return din;
}

ostream &operator<<(ostream &dout, Vector &b) // Frnd 4
{
    dout << "(";
    for (int i = 0; i < size220; i++)
    {
        dout << "," << b.v[i];
    }
    dout << ")";

    return dout;
}

int x[] = {1, 2, 3};

int main()
{
    Vector a;     // default constructor called
    Vector b = x; // equivalent to Vector b(x) parameterized constructor called
    int i = 2;
    Vector p;
    p = i * b; // Frnd 1 called

    Vector q;
    q = b * i; // Frnd 2 called

    cout << "Input for a 3d Vector";
    cin >> a; // Frnd 3 called

    // Frnd 4 called
    cout << "Vector a" << a << endl;
    cout << "Vector b" << b << endl;
    cout << "Vector p" << p << endl;
    cout << "Vector q" << p << endl;

    return 0;
}