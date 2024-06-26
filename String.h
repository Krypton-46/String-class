#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
enum Sign{POSITIVE,NEGATIVE};
class String
{
	char* data;
	int size;
public:
	String();
	String(const char);
	String(const char*);
	String(const String&);
	~String();
	bool isEmpty()const;
	void display()const;
	int getLength()const;
	int getSize()const;
	char& at(const int);
	const char& at(const int )const;
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void shrink();
	long long int convertToInteger()const;
	float convertToFloat()const;
	void reverse();
	int compare(const String&)const;
	void remove(const int , const int = 1);


