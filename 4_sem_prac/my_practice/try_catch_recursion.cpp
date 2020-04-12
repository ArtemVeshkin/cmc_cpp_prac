#include <iostream>

class Reverser
{
	int data_;
public:
	Reverser()
	{
		if (!(std::cin >> data_))
		{
			throw -1;
		}
	}

	~Reverser()
	{
		std::cout << data_ << std::endl;
	}
};

void process()
{
	Reverser r;
	try {
		process();
	} catch(const int &ex) {
		throw -1;
	} 
}

int main()
{
	try {
		process();
	} catch(const int &ex) {}
}