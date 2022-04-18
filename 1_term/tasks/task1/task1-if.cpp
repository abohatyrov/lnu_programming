#include <iostream>
using namespace std;
// ВАРІАНТ 4

int main() { // Завдання 1
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == d) {
		cout << "a = d, " << a << endl;
	}
	else if (b == d) {
		cout << "b = d, " << b << endl;
	}
	else if (c == d) {
		cout << "c = d, " << c << endl;
	}
	else {
		a = d - a;
		b = d - b;
		c = d - c;
		if (a > b && a > c) {
			cout << "a, b, c != d, " << "max = d - a, " << a << endl;
		}
		else if (b > a && b > c) {
			cout << "a, b, c != d, " << "max = d - b, " << b << endl;
		}
		else {
			cout << "a, b, c != d, " << "max = d - c, " << c << endl;
		}
	}
	return 0;
}

/*
int main() { // Завдання 2
	int x;
	cin >> x;
	if (x <= 1) {
		cout << x * x + 1 << endl;
	}
	else {
		cout << 1 / (double(x) + 6) << endl;
	}
	return 0;
}
*/