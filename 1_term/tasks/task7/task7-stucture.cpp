#include <iostream>
#include <string>

using namespace std;

struct Athlet_data
{
	string last_name;
	int fencing;
	int swimming;
	int jumping;
	int shooting;
	int running;
};

void input_athlet(Athlet_data& x);
string winner(Athlet_data* x, int size);

int main()
{
	int n;
	cout << "Enter number of athletes: ";
	cin >> n;
	cout << endl;

	Athlet_data* a = new Athlet_data[n];

	for (int i = 0; i < n; i++)
		input_athlet(a[i]);

	string winner_athlet = winner(a, n);
	cout << endl << "WINNER" << endl << winner_athlet << endl;
}

void input_athlet(Athlet_data& x)
{
	cout << "Enter last name: ";
	cin.ignore();
	getline(cin, x.last_name);
	cout << "Enter result of fencing: ";
	cin >> x.fencing;
	cout << "Enter result of swimming: ";
	cin >> x.swimming;
	cout << "Enter result of show jumping: ";
	cin >> x.jumping;
	cout << "Enter result of pistol shooting: ";
	cin >> x.shooting;
	cout << "Enter result of cross country running: ";
	cin >> x.running;
	cout << endl;
}

string winner(Athlet_data* x,const int size)
{
	int max_sum = 0;
	string win = " ";
	for (int i = 0; i < size; i++)
	{
		int sum = x[i].fencing + x[i].swimming + x[i].jumping + x[i].shooting + x[i].running;
		if (sum > max_sum)
		{
			max_sum = sum;
			win = x[i].last_name;
		}
	}
	return win;
}