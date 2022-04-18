#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str;
	size_t pos = 0, pos1 = 0;

	cout << "Enter string: ";
	getline(cin, str);

	char x = ' ';
	if (str.find(',') != string::npos)
		x = ',';

	while (true)
	{
		pos1 = str.find(x, pos);

		if (str.find('.') < pos1)
		{
			if ((str.find('.') - pos) % 2 != 0)
				str.erase((str.find('.') - pos) / 2 + pos, 1);
			break;
		}

		if ((pos1 - pos) % 2 != 0)
		{
			str.erase((pos1 - pos) / 2 + pos, 1);
			pos = pos1;
		}
		else
			pos = pos1 + 1;
	}

	cout << endl << "Result: " << str << endl;
	
	return 0;
}