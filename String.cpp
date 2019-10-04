<<<<<<< HEAD
#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
	MyString(const char *s = NULL);
	MyString(MyString& s);
	~MyString();

	void print();
	int getSize();
	MyString operator+(MyString& s)
	{
		char *temp = new char[getSize() + s.getSize() + 1];
		strcpy(temp, pBuf);
		strcat(temp, s.pBuf);
		MyString r(temp);
		delete [] temp;
		return r;
		/*MyString sn;
		sn.pBuf = new char [strlen(this->pBuf) + strlen(s.pBuf) + 1];
		strcat(this->pBuf, s.pBuf);
		return sn; */
	}

private:
	char *pBuf;
};

int main()
{
	MyString s1("Hello");
	MyString s2("World!");
	MyString s3;

	s3 = s1 + s2;

	s1.print();
	s2.print();
	s3.print();

	return 0;
}

MyString::MyString(const char *s)
{
	if(s == NULL)
	{
		pBuf = new char[1];
		pBuf[0] = NULL;
	}
	else
	{
		pBuf = new char[strlen(s) + 1];
		strcpy(pBuf, s);
	}
}

MyString::MyString(MyString& s)
{
	pBuf = new char[s.getSize() + 1];
	strcpy(pBuf, s.pBuf);
}

MyString::~MyString()
{
	if(pBuf)
		delete [] pBuf;
}

void MyString::print()
{
	cout << pBuf << endl;
}

int MyString::getSize()
{
	return strlen(pBuf);
}

=======
#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
	MyString(const char *s = NULL);
	MyString(MyString& s);
	~MyString();

	void print();
	int getSize();
	MyString operator+(MyString& s)
	{
		char *temp = new char[getSize() + s.getSize() + 1];
		strcpy(temp, pBuf);
		strcat(temp, s.pBuf);
		MyString r(temp);
		delete [] temp;
		return r;
		/*MyString sn;
		sn.pBuf = new char [strlen(this->pBuf) + strlen(s.pBuf) + 1];
		strcat(this->pBuf, s.pBuf);
		return sn; */
	}

private:
	char *pBuf;
};

int main()
{
	MyString s1("Hello");
	MyString s2("World!");
	MyString s3;

	s3 = s1 + s2;

	s1.print();
	s2.print();
	s3.print();

	return 0;
}

MyString::MyString(const char *s)
{
	if(s == NULL)
	{
		pBuf = new char[1];
		pBuf[0] = NULL;
	}
	else
	{
		pBuf = new char[strlen(s) + 1];
		strcpy(pBuf, s);
	}
}

MyString::MyString(MyString& s)
{
	pBuf = new char[s.getSize() + 1];
	strcpy(pBuf, s.pBuf);
}

MyString::~MyString()
{
	if(pBuf)
		delete [] pBuf;
}

void MyString::print()
{
	cout << pBuf << endl;
}

int MyString::getSize()
{
	return strlen(pBuf);
}

>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
