
#include <iostream>
using namespace std;
int main()
{
	int user_choice, comp_choice, toothpicks;
	char choice;
	do
	{  
		toothpicks = 23;
		cout << "Let's play a game of \"23\"!" << endl;
		cout << endl;
		while (toothpicks > 0)
		{  //User choice portion
			cout << "Enter the number of sticks you wish to pick: ";
			cin >> user_choice;
			cout << endl;
			while (user_choice > 3 || user_choice < 1 || user_choice > toothpicks)
			{
				if (user_choice > 3 || user_choice < 1)
				{
					cout << "Wrong number of sticks. Please pick 1, 2, or 3 sticks: ";
					cin >> user_choice;
					cout << endl;
				}
				else
				{
					cout << "Not enough sticks in pile. Please try again.";
					cin >> user_choice;
					cout << endl;
				}
			}
			toothpicks -= user_choice;

			cout << "You picked " << user_choice << " stick. " << toothpicks << " left" << endl;
			cout << endl;

			if (toothpicks == 0)
			{ //Computer wins output
				cout << "You picked the last stick." << endl;
				cout << endl;
				cout << "Sorry, the computer beat you!" << endl;
				cout << endl;
				break;
			}
			//Computer choice portion
			if (toothpicks > 4)
			{
				comp_choice = 4 - user_choice;
			}
			else if (toothpicks == 1)
			{
				comp_choice = toothpicks;
			}
			else 
			{
				comp_choice = toothpicks - 1;
			}

			toothpicks -= comp_choice;

			cout << "Computer picked " << comp_choice << " sticks. " << toothpicks << " left" << endl;
			cout << endl;

			if (toothpicks == 0)
			{ //User wins output
				cout << "Computer picked the last stick." << endl;
				cout << endl;
				cout << "You win!" << endl;
				cout << endl;
				break;
			}

			cout << "Your turn. ";
		} //Determines loop repeat or termination
			cout << "Do you want to play another game? <Y/N>: ";
			cin >> choice;
			cout << endl;
		
	}while (choice == 'Y' || choice == 'y');

	return 0;
}
