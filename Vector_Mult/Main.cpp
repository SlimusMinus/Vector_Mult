#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

const int _size = 10;
void Squaring();
void Mult_table();
void Write_2x_array(vector <int> vct, string str);
void Write_1x_array(vector <int> vct, string str);


int main()
{
	srand(time(NULL));
	Squaring();
	cout << "\n\n\n";
	Mult_table();
}

void Squaring()
{
	vector <int> vt;
	for (int i = 0; i < _size; i++)
	{
		int n = rand() % 25 + 3;
		vt.push_back(n);
	}
	for (auto it = vt.begin(); it != vt.end(); ++it)
		cout << *it << setw(5);

	cout << "\n*******************SQUARING**********************\n";
	for (auto it = vt.begin(); it != vt.end(); ++it)
		cout << (*it) * (*it) << setw(5);
	
	cout << "\n\n";
	
	Write_1x_array(vt, "SQUARING.txt");
	
}

void Mult_table()
{
	cout << "\n**********Multiplication_Table**********\n\n";

	vector <int> vect;
	for (int i = 1; i < _size; i++)
		vect.push_back(i);
	for (int i = 1; i < _size; i++)
	{
		for (auto it = vect.begin(); it != vect.end(); ++it)
			cout << setw(4) << (*it) * i;
		cout << endl;
	}
	cout << "\n\n";

	Write_2x_array(vect, "Multiplication_Table.txt");
}

void Write_2x_array(vector <int> vct, string str)
{
	ofstream fout;
	fout.open(str, ios::out | ios::binary);

	if (!fout.is_open())
		cout << "File is not open";
	else
	{
		cout << "File is open" << endl;
		for (int i = 0; i < _size; i++)
		{
			for (auto it = vct.begin(); it != vct.end(); it++)
			{
				fout << *it;
			}
		}
		cout << "End of write" << endl;
		fout.close();
	}
}

void Write_1x_array(vector <int> vct, string str)
{
	ofstream fout;
	fout.open(str, ios::out | ios::binary);

	if (!fout.is_open())
		cout << "File is not open";
	else
	{
		cout << "File is open" << endl;
		for (auto it = vct.begin(); it != vct.end(); it++)
		{
			fout << *it;
		}
		cout << "End of write" << endl;
		fout.close();
	}
}