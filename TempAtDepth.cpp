//Fort Hays State University - CSCI 121
//Project 4 - "The Temperature of Earth at a Depth"
//Author: Lindsey Jimenez
//Date: 09-29-2021

#include <iostream>
#include <cmath>

using namespace std;

void print_introduction();
double celsius_at_depth(double depth);
double fahrenheit_at_depth(double celsius);
void print_conclusion(double depth);

//the order of execution
int main()
{
	double depth;
	char choice;
	print_introduction();
	do
	{
		cout << "Enter a depth in KM: ";
		cin >> depth;
		print_conclusion(depth);
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	cout << "Program ended with exit code: 0\n";
	return 0;
}

void print_introduction()
{
	cout << "Hello! The program will tell you the temperature of the earth at any depth.\n";
}

//calculates temperature in celsius
double celsius_at_depth(double depth)
{
	return (10 * depth + 20);
}

//calculates temperature in fahrenheit
double fahrenheit_at_depth(double celsius)
{
	return (1.8 * celsius + 32);
}

void print_conclusion(double depth)
{
	double celsius = celsius_at_depth(depth);
	double fahrenheit = fahrenheit_at_depth(celsius);

	cout << "The temperature of the earth at a depth of " << depth << " KM is " << celsius << " in Celsius, and "
		<< fahrenheit << " in Fahrenheit.\n";

	cout << "Would you like to do it again? (Y/N): ";
}