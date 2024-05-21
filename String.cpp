#include"String.h"
#include"Extras.h"

String::String()
{
	data = nullptr;
	size = 0;
}

String::String(char c):String()
{
	size = 2;
	data = new char[size] { c,'\0' };
}

String::String(const char* c):String()
{
	if(c == nullptr)
		return;
	size = getStringLength(c)+1;
	data = new char[size];
	copyString(data,c);
}
String::String(const String & ref)
{
	if (ref.isEmpty())
		return;
	size = ref.size;
	data = new char[size];
	copyString(data, ref.data);
}
String::~String()
{
	if(data!=nullptr)
		delete[] data;
	data = nullptr;
	size = 0;
}

bool String::isEmpty()const
{
	if (data == nullptr || data[0] == '\0')
		return true;
	return false;
}

void String:: display() const
{
	if(data!=nullptr)
		cout << data;
}

int String::getLength()const
{
	if (data == nullptr)
		return -1;
	int i = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	return i;
}

int String::getSize()const
{
	return size;
}

char& String::at(int index)
{
	if (data == nullptr)
		exit(0);
	if (index >= 0 && index < getLength())
		return data[index];
	else 
		return data[0];
}

const char& String::at(const int index)const
{
	if (data == nullptr)
		exit(0);
	else if (index >= 0 && index < getLength())
		return data[index];
	else
		return data[0];
}



void String::trimLeft()
{
	if (data == nullptr)
		return;
	int i = 0;
	while (i < size && (data[i] == '\t' || data[i] == ' '||data[i]=='\n'))
	{
		i++;
	}
	if (i == 0)
		return;
	copyString(data, data + i);
}

void String::trimRight()
{
	if (data == nullptr)
		return;
	int i = getLength()-1;
	while (i>=0&&(data[i]=='\t'||data[i]==' '||data[i]=='\n'))
	{
		i--;
	}
	if (i < 0 && (data[0] == ' ' || data[0] == '\n' || data[0] == '\t'))
	{
		data[0] = '\0';
		return;
	}
	else if (i < 0)
		return;
	data[i + 1] = '\0';
}

void String::trim()
{
	trimLeft();
	trimRight();
}

void String::makeUpper()
{
	if (data == nullptr)
		return;
	int i = 0;
	while (data[i]!='\0')
	{
		if (data[i] >= 'a' && data[i] <= 'z')
			data[i] = data[i] - 32;
		i++;
	}
}

void String::makeLower()
{
	if (data == nullptr)
		return;
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
			data[i] = data[i]+ 32;;
		i++;
	}
}

void String::shrink()
{
	reSize(getLength());
}

long long int String::convertToInteger()const
{
	if (data == nullptr || data[0] == '\0' || ((data[0] > '9' && data[0] != '-')||(data[0] < '0' && data[0] != '-')))
		exit(0);
	Sign sign = POSITIVE;
	int i = 0;
	int num = 0;
	if (data[i] == '-')
	{
		i++;
		sign = NEGATIVE;
	}
	while (data[i] != '\0'&&data[i]>='0'&&data[i]<='9')
	{
		num = num * 10 + (data[i] - '0');
		i++;
	}
	if (sign == NEGATIVE)
		num = num * (-1);
	return num;
}

float String::convertToFloat()const
{
	if (data == nullptr || data[0] == '\0' || ((data[0] > '9' &&( data[0] != '.'&&data[0]!='-')) || (data[0] < '0' &&( data[0] != '.' && data[0] != '-'))))
	{
		exit(0);
	}
	Sign sign = POSITIVE;
	int i = 0;
	float num = 0;
	if (data[i] == '-')
	{
		i++;
		sign = NEGATIVE;
	}
	int counter = 0;
	while (data[i] != '\0'&&data[i]>='0'&&data[i]<='9')
	{
		num = num * 10 + (data[i] - '0');
		i++;
	}
	if (data[i] == '.')
	{
		i++;
		while (data[i] != '\0' && data[i] >= '0' && data[i] <= '9')
		{
			num = num * 10 + (data[i] - '0');
			counter++;
			i++;
		}
	}
	while (counter)
	{
		num = num / 10;
		counter--;
	}
	if (sign == NEGATIVE)
		num = num * (-1);
	return num;
}
