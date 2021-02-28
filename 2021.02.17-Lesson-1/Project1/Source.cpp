#include<iostream>
using namespace std;

void printInt(int x)
{
	int bitlength = sizeof(x) * 8;
	for (int i = bitlength - 1; i >= 0; --i)
	{
		int bit = x;
		bit = (bit >> i) & 1;
		cout << bit;
	}
}

void printLong(long x)
{
	int bitlength = sizeof(x) * 8;
	for (int i = bitlength-1; i >= 0; --i)
	{
		long bit = x;
		bit = (bit >>i)&1;
		cout << bit;
	}
}

void printLongLong(long long x)
{
	int bitlength = sizeof(x) * 8;
	for (int i = bitlength - 1; i >= 0; --i)
	{
		long long bit = x;
		bit = (bit >> i) & 1;
		cout << bit;
	}
}

void printFloat(float x)
{
	void* ptr = &x;
	long xl = *((long*)ptr);
	int bitlength = sizeof(xl) * 8;
	for (int i = bitlength - 1; i >= 0; --i)
	{
		long bit = xl;
		bit = (bit >> i)&1;
		cout << bit;
	}
}


void printDouble(double x)
{
	void* ptr = &x;
	long long xl = *((long long*)ptr);
	int bitlength = sizeof(xl) * 8;
	for (int i = bitlength - 1; i >= 0; --i)
	{
		long long bit = xl;
		bit = (bit >> i) & 1;
		cout << bit;
	}
}

void printLongDouble(long double x)
{
	void* ptr = &x;
	long long xl = *((long long*)ptr);
	int bitlength = sizeof(xl) * 8;
	for (int i = bitlength - 1; i >= 0; --i)
	{
		long long bit = xl;
		bit = (bit >> i) & 1;
		cout << bit;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� ���������� a ���� int:" << endl << "a = ";
	int a;
	cin >> a;
	printInt(a);
	cout << endl << endl;

	cout << "������� �������� ���������� b ���� long:" << endl << "b = ";
	long b;
	cin >> b;
	printLong(b);
	cout << endl<< endl;

	cout << "������� �������� ���������� c ���� long long:" << endl << "c = ";
	long long c;
	cin >> c;
	printLongLong(c);
	cout << endl << endl;

	cout << "������� �������� ���������� d ���� float:" << endl << "d = ";
	float d;
	cin >> d;
	printFloat(d);
	cout << endl << endl;

	cout << "������� �������� ���������� e ���� double:" << endl << "e = ";
	double e;
	cin >> e;
	printDouble(e);
	cout << endl << endl;

	cout << "������� �������� ���������� f ���� long double:" << endl << "f = ";
	long double f;
	cin >> f;
	printLongDouble(f);
	cout << endl;

	return 0;
}