#include <iostream>

using namespace std;

// 4 ��в���

int main()
{
	int p;
	cout << "Enter size off array: ";
	cin >> p;
	auto* arr = new int[p];
	int L, M, n;
	
	cout << "Enter number L: ";
	cin >> L;
	cout << "Enter number M: ";
	cin >> M;
	cout << "Enter array: ";
	for (auto i = 0; i < p; i++)
	{
		cin >> n;
		arr[i] = n;
	}
	cout << endl;
	
	for (auto i = 0; i < p; i++)
		if (arr[i] % M == L)
			cout << arr[i] << ' ';
	cout << endl;
}