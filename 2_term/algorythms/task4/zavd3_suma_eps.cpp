#include <iostream>
#include <cmath>

using namespace std;

double power(double x, int n);

int main()
{
    int n = 0;
    double a = 0, x, eps, k = 1;

    cout << "Enter x: "; cin >> x;
    cout << "Enter eps: "; cin >> eps;

    do
    {
        a += k * (power(x, 2 * n + 1) / (2 * n + 1));
        cout << "a = " << a;
        cout << "\t|arctg(x) - a| = " << fabs(atan(x) - a) << endl;
        n++;
        k *= -1;
    } while (fabs(atan(x) - a) >= eps);

    cout << "Result: \na = " << a << "\tarctg(x) = " << atan(x) << endl;
}

double power(double x, int n)
{
    double y = 1;
    for (int i = 1; i <= n; i++)
        y *= x;
    return y;
}