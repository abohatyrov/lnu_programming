#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    double sum = 0, a = 0, x, eps, k = 1;

    cout << "Enter |x| < 1: "; cin >> x;
    cout << "Enter eps > 1: "; cin >> eps;

    double c = x;
    do
    {
        a = k * (c / (2 * n + 1));
        sum += a;
        cout << "|a| = " << abs(a) << endl;
        n++;
        k *= -1;
        c *= x * x;
    } while (abs(a) >= eps);

    cout << "Result: \na = " << a << "\tsum = " << sum << "\tarctg(x) = " << atan(x) << endl;
}
