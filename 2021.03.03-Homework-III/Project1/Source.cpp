#include<iostream>
#include<string>
#include<fstream>

using namespace std;

bool isSign(char c);
bool isDigit(char c);
bool isDot(string str, int& index);
bool isE(string str, int& index);
bool isNatural(string str, int& index);
bool isExp(string str, int& index);
bool isMantis(string str, int& index);
bool isReal(string str, int& index);

int main()
{
	string str;
	int index = 0;
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin >> str;
	cout << str;
	fout << str;
	if (isReal(str, index))
	{
		fout << '=)';
	}
	else
	{
		fout << '=(';
	}

	fout.close();
	fin.close();
	return 0;
}


bool isReal(string str, int& index)
{
	if (isSign(str[index]))
	{
		++index;
	}
	if (isMantis(str, index) && isExp(str, index) && str[index] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isMantis(string str, int& index)
{
	if (isNatural(str, index) && isDot(str, index) && isNatural(str, index))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isExp(string str, int& index)
{
	if (!isE(str, index))
	{
		return false;
	}
	if (isSign(str[index]))
	{
		++index;
	}
	if (isNatural(str, index))
	{
		return true;
	}
	return false;
}

bool isNatural(string str, int& index)
{
	cout << str[index];
	if (!isDigit(str[index]))
	{
		return false;
	}
	while (isDigit(str[++index]));
	return true;
}

bool isDigit(char c)
{
	return c <= '9' || c >= '0';
}

bool isDot(string str, int& index)
{
	if (str[index] == '.')
	{
		++index;
		return true;
	}
	return false;
}

bool isE(string str, int& index)
{
	if (str[index] == 'E')
	{
		++index;
		return true;
	}
	return false;
}

bool isSign(char c)
{
	return c == '+' || c == '-';
}



/*������� ������������ ����� ���������� ��������� ������� :
<������������ �����> :: = <��������> <�������> | <����> <��������> <�������>
<��������> :: = . <����� ��� �����> | <����� ��� �����> . <����� ��� �����>
<�������> :: = E <����� ��� �����> | E <����> <����� ��� �����>
<����� ��� �����> :: = <�����> | <�����> <����� ��� �����>
<�����> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
< ���� > :: = +| - */
