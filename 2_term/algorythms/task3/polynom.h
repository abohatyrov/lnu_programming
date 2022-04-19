#include <iostream>
#include <string>

using namespace std;

class Polynom
{
private:
    double* a; // Multipliers
    int n; // Power
public:
    Polynom(){}; // Empty constructor
    Polynom(const Polynom& pol); // Copy constructor
    Polynom(int count); // Empty constructor with power
    Polynom operator+(Polynom pol); // Sum operation
    Polynom operator-(Polynom pol); // Subtraction operation
    Polynom operator*(Polynom pol); // Multiplication operation
    Polynom derivative(); // Find derivative
    double value(double x); // Find value of polynom (Horner's method)
    friend istream& operator >>(istream& os, Polynom& pol); // Input polynom
    friend ostream& operator <<(ostream& os, Polynom& pol); // Output polynom
};

Polynom::Polynom(int count)
{ // Empty constructor with power
        n=count;
        a=new double[n+1];
}
 
Polynom::Polynom(const Polynom& pol)
{ // Copy constructor
        n=pol.n;
        a=new double[n + 1];
        for(int i = 0; i <= n; i++)
            a[i] = pol.a[i];
}

Polynom Polynom::operator+(Polynom pol)
{ // Sum operation
    Polynom temp = Polynom();

    if (n > pol.n)
    {
        temp = *this;
        for (int i = 0; i < temp.n; i++)
            temp.a[i] += pol.a[i];
    }
    else
    {
        temp = pol;
        for (int i = 0; i < temp.n; i++)
            temp.a[i] += a[i];
    }

    return temp;
}

Polynom Polynom::operator-(Polynom pol)
{ // Subtraction operation
    Polynom temp = Polynom();
    int min_n = 0;
    if (n > pol.n)
    {
        temp = *this;
        min_n = pol.n;
    }
    else
    {
        temp = pol;
        min_n = n;
        for (int i = pol.n + 1; i > min_n; i--) temp.a[i] *= -1;
    }

    for (int i = 0; i <= min_n; i++)
        temp.a[i] = a[i] - pol.a[i];

    return temp;
}

Polynom Polynom::operator*(Polynom pol)
{ // Multiplication operation
    Polynom temp(n + pol.n);

    if (n > pol.n)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= pol.n; j++)
                temp.a[i + j] += (a[i] * pol.a[j]);
    else
        for(int i = 0; i <= pol.n; i++)
            for(int j = 0; j <= n; j++)
                temp.a[i + j] += (a[j] * pol.a[i]);

    return temp;
}

Polynom Polynom::derivative()
{ // Find derivative
    Polynom temp(n - 1);

    for (int i = 1; i <= n; i++)
        temp.a[i - 1] = i * a[i];

    return temp;
}

double Polynom::value(double x)
{ // Find value of polynom (Horner's method)
    double value = a[n + 1];

    for (int i = n + 1; i > 1; i--)
        value = value * x + a[i-1];

    return value + a[0];
}

istream& operator >>(istream& os, Polynom& pol)
{ // Input polynom
    // cout << "Enter polynom power: ";
    int n;
    os >> n;
    pol.n = n;
    double* b = new double[n + 1];
    
    // cout << "Enter multipliers: \n";
    for (int i = 0; i <= n; i++)
    {
        // cout << "a[" << i << "] = ";
        os >> b[i];
    }
    pol.a = b;

    return os;
}

ostream& operator <<(ostream& os, Polynom& pol)
{ // Output polynom
    for (int i = pol.n; i >= 0; i--)
    {
        if (pol.a[i] != 0)
        {
            if (i == pol.n)
            {
                if (i == 1)
                    if (pol.a[i] == 1)
                        os << "x ";
                    else if (pol.a[i] == -1)
                        os << "- x ";
                    else if (pol.a[i] > 0)
                        os << pol.a[i] << "x ";
                    else
                        os << "- " << pol.a[i] * -1 << "x ";
                else
                    if (pol.a[i] == 1)
                        os << "x^" << i << ' ';
                    else if (pol.a[i] == -1)
                        os << "- x^" << i << ' ';
                    else if (pol.a[i] > 0)
                        os << pol.a[i] << "x^" << i << ' ';
                    else
                        os << pol.a[i] * -1 << "x^" << i << ' ';
            }
            else if (i == 0)
            {
                if (pol.a[i] > 0)
                    os << "+ " << pol.a[i] << ' ';
                else
                    os << "- " << pol.a[i] * -1 << ' ';
            }
            else if (i == 1)
            {
                if (pol.a[i] == 1)
                    os << "+ x ";
                else if (pol.a[i] == -1)
                    os << "- x ";
                else if (pol.a[i] > 0)
                    os << "+ " << pol.a[i] << "x ";
                else
                    os << "- " << pol.a[i] * -1 << "x ";
            }
            else
            {
                if (pol.a[i] == 1)
                    os << "+ x^" << i << ' ';
                else if (pol.a[i] == -1)
                    os << "- x^" << i << ' ';
                else if (pol.a[i] > 0)
                    os << "+ " << pol.a[i] << "x^" << i << ' ';
                else
                    os << "- " << pol.a[i] * -1 << "x^" << i << ' ';
            }
        }
    }

    return os;
}
