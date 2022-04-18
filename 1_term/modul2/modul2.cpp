// Ввести інформацію про n газет: назва, рік заснування, тираж (наприклад,
// Express 1986 10000). Виконати наступні дії:
// 1. записати у масив;
// 2. вивести масив на екран у вигляді послідовності стрічок з інформацією про
// об’єкти;
// 3. вивести назву найстарішої газети;
// 4. вивести назви газет, що починаються на букву “і”;
// 5. знайти всі газети тиражом понад 500 примірників.
// Всі дії оформити у вигляді відповідних функцій.

#include <iostream>
#include <string>

using namespace std;

struct NewsPaper
{
	string name;
	int year;
	int circulation;
};

void Input_NewsPaper(NewsPaper& a);
void Output_NewsPaper(NewsPaper a);
NewsPaper Oldest_NewsPaper(NewsPaper* a, const size_t size);
NewsPaper* I_NewsPaper(NewsPaper* a, size_t& size);
NewsPaper* Over500_NewsPaper(NewsPaper* a, size_t& size);

int main()
{
	size_t n;
	cout << "\nEnter number of newspapers: ";
	cin >> n;
	cout << endl;

	NewsPaper* np_arrey = new NewsPaper[n];

	for (size_t i = 0; i < n; i++)
		Input_NewsPaper(np_arrey[i]);

	cout << "+ Newspapers information +\n\n";
	for (size_t i = 0; i < n; i++)
	{
		cout << "Newspaper #" << i + 1 << endl;
		Output_NewsPaper(np_arrey[i]);
	}

	NewsPaper oldest = Oldest_NewsPaper(np_arrey, n);
	cout << "+ The oldest newspaper +\n\n" << "Name: " << oldest.name << endl << "Years: " << 2021 - oldest.year << endl;

    size_t m = n;
	NewsPaper* i_ = I_NewsPaper(np_arrey, m);
	for (size_t i = 0; i < m; i++)
		cout << i_[i].name << endl;
	cout << endl;

    m = n;
	NewsPaper* over500 = Over500_NewsPaper(np_arrey, m);
	cout << "+ Newspapers which have circulation more then 500 +\n\n";
	for (size_t i = 0; i < m; i++)
	{
		cout << "Name: " << over500[i].name << endl;
		cout << "Circulation: " << over500[i].circulation << endl << endl;
	}
}

void Input_NewsPaper(NewsPaper& a)
{
	cout << "Enter name of newspaper: ";
	cin.ignore();
	getline(cin, a.name);
	cout << "Enter year of foundation: ";
	cin >> a.year;
	cout << "Enter circulation: ";
	cin >> a.circulation;
	cout << endl;
}

void Output_NewsPaper(NewsPaper a)
{
	cout << "Name of newspaper: " << a.name << endl;
	cout << "Year of foundation: " << a.year << endl;
	cout << "Circulation: " << a.circulation << endl << endl;
}

NewsPaper Oldest_NewsPaper(NewsPaper* a, const size_t size)
{
	NewsPaper oldest;
	oldest.year = 0;

	for (size_t i = 0; i < size; i++)
		if (a[i].year > oldest.year)
			{
				oldest.name = a[i].name;
				oldest.year = a[i].year;
				oldest.circulation = a[i].circulation;
			}
	return oldest;
}

NewsPaper* I_NewsPaper(NewsPaper* a, size_t& size)
{
	NewsPaper* i_ = new NewsPaper[size];
	size_t t = 0;
	size_t count = 0;

	for (size_t i = 0; i < size; i++)
		for (size_t j = t; j < size; j++)
			if (a[j].name.find("I") == 0 || a[j].name.find("i") == 0)
			{
				i_[i].name = a[j].name;
				i_[i].year = a[j].year;
				i_[i].circulation = a[j].circulation;
				count++;
				t = j + 1;
				break;
			}
    size = count;
	if (count == 0)
	{
		cout << endl << "+ No names which begin on 'I' +\n\n";
		return i_;
	}
	else{
        cout << endl << "+ Names which begin on 'I' +\n\n";
		return i_;
	}
}

NewsPaper* Over500_NewsPaper(NewsPaper* a, size_t& size)
{
	NewsPaper* over500 = new NewsPaper[size];
	size_t t = 0;
	size_t count = 0;

	for (size_t i = 0; i < size; i++)
		for (size_t j = t; j < size; j++)
			if (a[j].circulation > 500)
			{
				over500[i].name = a[j].name;
				over500[i].year = a[j].year;
				over500[i].circulation = a[j].circulation;
				count++;
				t = j + 1;
				break;
			}
    size = count;
	return over500;
}