<<<<<<< HEAD
#include <iostream>

using namespace std;

class MyArray
{
	friend ostream& operator<<(ostream&, const MyArray &);
private:
	int *data;
	int size;

public:
	MyArray(int size = 10);
	~MyArray();

	int getSize() const;
	MyArray& operator=(const MyArray &a);
	int& operator[](int i);
};

MyArray::MyArray(int s)
{
	size = (s > 0 ? s : 10);
	data = new int[size];

	for(int i =0; i < size; i++)
		data[i] = 0;
}

MyArray::~MyArray()
{
	delete [] data;
	data = NULL;
}

MyArray& MyArray::operator = (const MyArray& a)
{
	if(&a != this)
	{
		delete [] data;
		size = a.size;
		data = new int[size];

		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
	}

	return *this;
}

int MyArray::getSize() const
{
	return size;
}

int& MyArray::operator[](int index)
{
	assert( 0 <= index && index < size);
	return data[index];
}

ostream& operator<<(ostream &output, const MyArray &a)
{
	int i;
	for(i=0; i <a.size; i++)
	{
		cout << a.data[i] <<'';
	}

	output << endl;
	return output;
}

int main()
{
	MyArray a1(10);

	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;
	cout << a1;

	return 0;
}
=======
#include <iostream>

using namespace std;

class MyArray
{
	friend ostream& operator<<(ostream&, const MyArray &);
private:
	int *data;
	int size;

public:
	MyArray(int size = 10);
	~MyArray();

	int getSize() const;
	MyArray& operator=(const MyArray &a);
	int& operator[](int i);
};

MyArray::MyArray(int s)
{
	size = (s > 0 ? s : 10);
	data = new int[size];

	for(int i =0; i < size; i++)
		data[i] = 0;
}

MyArray::~MyArray()
{
	delete [] data;
	data = NULL;
}

MyArray& MyArray::operator = (const MyArray& a)
{
	if(&a != this)
	{
		delete [] data;
		size = a.size;
		data = new int[size];

		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
	}

	return *this;
}

int MyArray::getSize() const
{
	return size;
}

int& MyArray::operator[](int index)
{
	assert( 0 <= index && index < size);
	return data[index];
}

ostream& operator<<(ostream &output, const MyArray &a)
{
	int i;
	for(i=0; i <a.size; i++)
	{
		cout << a.data[i] <<'';
	}

	output << endl;
	return output;
}

int main()
{
	MyArray a1(10);

	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;
	cout << a1;

	return 0;
}
>>>>>>> 703c4cd30b5df7fc525d0c1e7238cdd23ea21d06
