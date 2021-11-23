#include <iostream>
using namespace std;


int sum(int n)
{
	if (n == 0)
		return 0;
	return n + sum(n - 1);
	
}
int str_length(char s[], int counter)
{
	if (s[counter] == '\0')
		return 0;
	return	1+ str_length(s, counter + 1);
}

int main()
{
	char choice;
	int n;
	char str[100];

	do
	{
		cout << "Enter a positive integer: ";
		cin >> n;
		cout << "The sum of 1+2+...+ " << n << " is: " << sum(n) << endl;

		cout << "\nEnter a sentence: ";
		cin.ignore();
		cin.getline(str, 99);
		cout << "It contains " << str_length(str,0) << " chars, including white spaces\n" << endl;

		cout << "Do you want to have another run? Y/N: ";
		cin >> choice;
		cout << endl;

	} while (choice == 'Y' || choice == 'y');

	cout << "Program ended with exit code: 0";
	return 0;
}