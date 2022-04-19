#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Task 1\n";
    int k = 1;
    double x = 1, n = -1;

    while (abs(x - sqrt(2) / 2) > 0.000001)
    {
        x *= (1 + (n / (2 * k + 1)));
        // cout << x << "\tK: " << k << "\tFault: " << abs(x - sqrt(2)/2) << endl;
        n *= -1; 
        k++;
    }
    cout << "Count: " << k << endl;
}
