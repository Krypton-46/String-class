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

String::String(const char* c):String()
{
	if(c == nullptr)
		return;
	size = getStringLength(c)+1;
	data = new char[size];
		copyString(data,c);
}

void String:: display() const
{
	if(data!=nullptr)
		cout << data;
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

String::String(const String & ref)
{
	if (ref.isEmpty())
		return;
	size = ref.size;
	data = new char[size];
	copyString(data, ref.data);
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
String::~String()
{
	if(data!=nullptr)
		delete[] data;
	data = nullptr;
	size = 0;
}
