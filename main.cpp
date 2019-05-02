#include "source.hpp"

int main()
{
	//example

	HashTable table;

	for (;;)
	{
		cout << "Name and age the object: ";

		string name;
		int	   age;

		cin >> name >> age;

		table.push_back(name, age);

		cout << "Do you want continue? Y / N" << endl;
		char choose = 'Y';

		cin >> choose;

		if (choose == 'N')
		{
			break;
		}
	}

	Identifier* iden = table.find("Tiam");

	if (iden)
	{
		cout << "Name '" << iden->get_name() <<"' was found" << endl;
	}

	iden = table.find("SA");

	if (iden)
	{
		cout << "Name '" << iden->get_name() << "' was found" << endl;
	}

	system("pause");
	return 0;
}