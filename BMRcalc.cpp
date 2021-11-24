
#include <iostream>
using namespace std;

int main()
{
	double weight, height, age, bmr, choco_bars;
	char gender;
	char x;
	cout << "Welcome to my BMR calculator." << endl;
	do
	{
		cout << "Gender (M or F): ";
		cin >> gender;
		while (gender != 'f' && gender != 'F' && gender != 'm' && gender != 'M')
		{
			cout << "Wrong gender input. Please enter again. Gender (M or F): ";
			cin >> gender;
		}
		cout << "Weight (in pounds): ";
		cin >> weight;
		cout << "Height (in inches): ";
		cin >> height;
		cout << "Age (in years): ";
		cin >> age;
		if (gender == 'F' || gender == 'f')
		{
			bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
			choco_bars = bmr / 230;
			cout << "She needs " << bmr << " calories to maintain her weight." << endl;
			cout << "That is about " << choco_bars << " chocolate bar's calories." << endl;
		}
		else if (gender == 'M' || gender == 'm')
		{
			bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
			choco_bars = bmr / 230;
			cout << "He needs " << bmr << " calories to maintain his weight." << endl;
			cout << "That is about " << choco_bars << " chocolate bar's calories." << endl;
		}
		cout << "Do you want to do another calculation? (Y/N):";
		cin >> x;
	} while (x == 'y' || x == 'Y');
	if (x == 'n' || x == 'N')
	{
		cout << "Thanks for using my BMR calculator. Good bye!" << endl;
		cout << "Program ended with exit code: 0" << endl;
	}
}
