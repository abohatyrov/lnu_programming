#include <iostream>
#include <cmath>

using namespace std;

double power(double x, int n);

int main()
{
    int n = 1;
    double arctg = 0, x = 0.4, eps = 0.002;

    while (fabs(arctg) >= eps)
    {
        int k;
        n % 2 == 0 ? k = 1 : k = -1;
        cout << k;

        arctg += k * (power(x, 2 * n + 1) / (2 * n + 1));
        n++;
    }
    cout << arctg;
}

double power(double x, int n)
{
    double y = 1;
    for (int i = 1; i <= n; i++)
        y *= x;
    return y;
}