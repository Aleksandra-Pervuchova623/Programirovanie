#include<iostream>
using namespace std;

void bubbleSort(int* a, int len, int& numberSwap, int& numberComp);
void insertionSort(int* a, int len, int& numberSwap, int& numberComp);
void selectionSort(int* a, int len, int& numberSwap, int& numberComp);


int main()
{
	setlocale(LC_ALL, "Russian");
	for (int j = 5; j <= 20; j += 5)
	{
		int len = j;
		int* a = new int[len] {0};
		int swap[3] = { 0 };
		int comp[3] = { 0 };
		int sumS[3] = { 0 };
		int sumC[3] = { 0 };
		void (*sort[3])(int*, int, int&, int&) { bubbleSort, insertionSort, selectionSort };
		for (int i = 0; i < 1000; ++i)
		{
			for (int i = 0; i < 3; ++i)
			{
				for (int i = 0; i < len; ++i)
				{
					a[i] = rand() % 100;
				}

				sort[i](a, len, swap[i], comp[i]);
				sumS[i] += swap[i];
				sumC[i] += comp[i];
			}
		}
		cout << " ������ ����� " << j << endl;
		string name[3] = { "�������", "�������", "�����" };
		for (int i = 0; i < 3; ++i)
		{
			cout << name[i] << ": ";
			cout << sumS[i] / 1000 << " ���������" << ", ";
			cout << sumC[i] / 1000 << " ������������" << endl;
		}
		cout << endl;
		delete[] a;
	}
	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void bubbleSort(int* a, int len, int& numberSwap, int& numberComp)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				++numberSwap;
			}
			++numberComp;
		}
	}
}

void insertionSort(int* a, int len, int& numberSwap, int& numberComp)
{
	for (int i = 1; i < len; ++i)
	{
		int t = a[i];
		int j = i;
		while (a[j - 1] > t && j > 0)
		{
			a[j] = a[j - 1];
			--j;
			++numberSwap;
		}
		a[j] = t;
		++numberComp;
	}
	numberSwap += len - 1;
}

void selectionSort(int* a, int len, int& numberSwap, int& numberComp)
{
	for (int i = 0; i < len; ++i)
	{
		int index = i;
		for (int j = 1; j < len; ++j)
		{
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
	numberSwap = len;
	numberComp = len * (len - 1);
}

void ascending(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}
}

void descending(int* a, int len)
{
	for (int i = len - 1; i >= 0; --i)
	{
		a[i] = i;
	}
}



/*������� ������������ ������, ��������� ��� ���������� �������, ������������� ��� ����� �������� �������� : �������, �������, �����.
������ ���������� ��������� �� 1000 ��� � ������� ������� ���������� ��������� � ������� ���������� ������������ ��� ������ �� ����������.
�������� ���������� ��� �������� ������ 5, 10, 15 � 20.
�������� ����������� ���������� ������� ������� ������ ������� �� ����������� � �� ��������(����� ��� �������� ������������ ��������
���������� ��������� � ���������� ������������).*/











