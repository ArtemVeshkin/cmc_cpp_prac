#include <iostream>

class String
{
	struct Buf;
public:
	size_t size()
	{
		
	}
};

struct String::Buf
{
	bool unique = true;
	char *buf;
	size_t size;

	Buf(char *str)
	{
		char *ptr = str;
		for (int i = 0; str[i] != )
		{
			buf[i] = ptr[i];
		}
	}
};

int main()
{
	String c, a = "abc";
	String b = a; // в памяти хранится "abc" в одном экземпляре 
	c = a; 
	b += "aaa"; // для b создался новый "массив" символов.
	c[1] = 'f'; // a не изменилось 
	std::cout << String(c);
}