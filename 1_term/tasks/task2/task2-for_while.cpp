#include <iostream>
#include <cmath>
using namespace std;
// 4 ��в���


int main() // �������� 1
{
   double a, b, h, x = 0, y = 0, max = 0;
   int count = 0;
   cout << "Enter a: ";
   cin >> a;
   cout << "Enter b: ";
   cin >> b;
   cout << "Enter h: ";
   cin >> h;
   cout << endl << "x | y" << endl;
   for (double i = a; i <= b; i += h)
   {
       x = i;
       y = x * sin(x);
       cout << x << " | " << y << endl;
       if (y < 0)
           count++;
       if (max < y)
           max = y;
   }
   cout << endl << "The count of negative y = " << count << endl << "Maximum value of y = " << max << endl;
    double n, p = (1 + 1. / 3) * (2 + 1. / 6);
    cout << "n: "; cin >> n;
    while (n > 2)
    {
        p *= n + 1. / (3 * n);
        n--;
    }
    cout << floor(p * 100) / 100 << endl;
   return 0;
} 


// int main() // �������� 2
// {
//     double n, p = (1 + 1. / 3) * (2 + 1. / 6);
//     cin >> n;
//     while (n > 2)
//     {
//         p *= n + 1. / (3 * n);
//         n--;
//     }
//     cout << floor(p * 100) / 100 << endl;
//     return 0;
// }