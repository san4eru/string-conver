#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class String
{
private:

	char *str;
	char *str_temp;
	int length;

public:

	String();
	String(char *);

	~String();

	void Set(char *);

	void Print();

	void Print_File();

	char* Run();

	String& operator = (const String &);

	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
};

String::String()
{
	str = nullptr;
	str_temp = nullptr;
	length = 0;
}

String::String(char *str)
{
	length = strlen(str);

	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
		this->str[i] = str[i];

	this->str[length] = '\0';

	str_temp = new char[length + 1];
	for (int i = 0; i < length; i++)
		str_temp[i] = str[i];
	str_temp[length] = '\0';
}

String::~String()
{
	delete[] this->str;
	delete[] this->str_temp;
}

void String::Set(char *str)
{
	int i = 0;
	for (i = 0; i < strlen(str); i++)
		this->str[i] = str[i];
	this->str[i] = '\0';
}

void String::Print()
{
	cout << str << endl;
}

void String::Print_File()
{
	FILE *fout;

	fout = fopen("output.txt", "w");

	fprintf(fout, "%s", str);
	fprintf(fout, "\n");
	fprintf(fout, "%s", str_temp);

	fclose(fout);
}

char* String::Run()
{
	if ((length > 5) && (length < 30))
	{
		int i = 0;
		for (i = 0; i < length; i++)
		{
			if (str[i] >= 97)
				str_temp[i] = (char)((int)str[i] - 32);

			if (str[i] <= 90)
				str_temp[i] = (char)((int)str[i] + 32);
		}
		str_temp[i] = '\0';
		return str_temp;
	}
	else
		return str;
}

String& String::operator = (const String &other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}

	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';

	return *this;
}

ostream& operator << (ostream& os, String &other) {
	os << other.str;
	return os;
}

istream& operator >> (istream& is, String & other) {
	is >> other.str;
	return is;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char input[255];

	cout << "Введите строку [MAX = 255]: "; cin >> input;
	String S1(input);

	cout << "Вы ввели строку: ";
	S1.Print();

	cout << "Преобразованная строка S1: " << S1.Run() << endl << endl;
	S1.Print_File();

	String *S2;
	S2 = new String();

	(*S2) = S1;

	cout << "Строка S2: ";
	S2->Print();

	cout << "Преобразованная строка S2: " << S2->Run() << endl << endl;

	delete S2;

	system("pause");
	return 0;
}