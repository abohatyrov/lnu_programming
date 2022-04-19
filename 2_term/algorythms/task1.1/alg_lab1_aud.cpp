#include <iostream>

using namespace std;

double rec(double a, double x, double e)
{
    // Lab 1
    double y = 0.5 * (a + x/a);
    cout << "A: " << a << "\tY: " << y << "\tDifference: " << abs(a * a - y * y) << endl;

    if (abs(a * a - y * y) < e) return a;
    
    return rec(y, x, e);
}

int main()
{
    cout << "Lab 1\n";
    double a, x, e;
    cin >> a >> x >> e;
    double answer = rec(a, x, e);
    cout << "Answer: " << answer << endl;
}
