#include <iostream>

using namespace std;

unsigned long long Binom(int, int);

int main()
{
    int n, m;
    cout << "Enter n: "; cin >> n;
    cout << "Enter m: "; cin >> m;
    cout << "Binomial coefficient: " << Binom(m, n) << endl;
}

unsigned long long Binom(int m, int n)
{
    if (m == 0 || m == n) return 1;
    else if (m == 1) return n;
    else if (m > n / 2) m = n - m;

    return Binom(m, n - 1) + Binom(m - 1, n - 1);
}