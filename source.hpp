#include <iostream>
#include <string>

#define PRIME_SIZE 228

using namespace std;

class Identifier
{
public:
	Identifier(const string& name, const int& age) :
		name(name),
		age(age)
	{	
	}

	~Identifier()
	{
		delete next;
	}

	Identifier*& get_next() { return next; }
	string get_name() const { return name; }
private:
	Identifier* next{};
	string	    name;
	int	        age{};
};

class HashTable
{
public:
	~HashTable()
	{
		for (auto& tab : table)
		{
			delete tab;
		}
	}

	void push_back(const string& name, const int& age)
	{
		const int   hashNumber  = hash(name);

		Identifier* iden		= new Identifier(name, age),
				  * place		= table[hashNumber];

		if (place == nullptr)
		{
			table[hashNumber] = iden;
			return;
		}

		for (; place->get_next() != nullptr; place = place->get_next());

		place->get_next() = iden;
	}

	Identifier* find(const string& name)
	{
		const int   hashNumber  = hash(name);

		Identifier* result		= table[hashNumber];

		if (result == nullptr)
		{
			cout << "Name wasn't found" << endl;
			return nullptr;
		}

		for (; result->get_name() != name; result = result->get_next())
		{
			if (result->get_next() == nullptr)
			{
				cout << "Name wasn't found" << endl;
				return nullptr;
			}
		}

		return result;
	}

private:
	Identifier* table[PRIME_SIZE]{};

	static int hash(const string& name)
	{
		auto ascii = 0;

		for (char nam : name)
		{
			ascii += nam * 31;
		}

		return ascii % PRIME_SIZE;
	}
};
