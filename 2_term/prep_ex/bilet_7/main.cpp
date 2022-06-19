#include <iostream>
#include "vector3.h"

using namespace std;

int main()
{
    Vector3<int> v1;
    Vector3<int> v2;
    int s;

    cout << "Input vector1: ";
    cin >> v1;
    cout << "Input vector2: ";
    cin >> v2;
    cout << "Input scalar: ";
    cin >> s;
    cout << endl;

    Vector3<int> v_sum = v1 + v2;
    Vector3<int> v_difference = v1 - v2;
    Vector3<int> v_mult_on_scalar1 = v1 * s;
    Vector3<int> v_mult_on_scalar2 = v2 * s;
    int scalar_product = v1 * v2;

    cout << "Sum: " << v_sum << "\n\n";
    cout << "Difference: " << v_difference << "\n\n";
    cout << "Multipliar on scalar: " << v_mult_on_scalar1 << ", " << v_mult_on_scalar2 << "\n\n";
    cout << "Scalar product: " << scalar_product << "\n\n";

}