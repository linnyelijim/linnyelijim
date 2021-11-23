#include <iostream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

void get_scores(vector<int>& v)
{
		int score;
		cout << "Enter scores, enter -1 to stop: \n";
		
			do
			{
				cin >> score;
				if (score >= 0)
					v.push_back(score);

			} while (score >= 0);
	
		
}	

 
void print_stats(vector<int>& v)
{
	if (v.size() > 0)
	{
		int min = v.at(0);
		int max = v.at(0);
		int sum = 0;
		double avg;
	
		for (int i = 0; i < v.size(); i++)
		{
			sum += v.at(i);
			if (max < v.at(i))
				max = v.at(i);
			if (min > v.at(i))
				min = v.at(i);

		}
		avg = sum * 1.0 / v.size();
		cout << "There are total " << v.size() << " scores" << endl;
		cout << "The highest score is: " << max << endl;
		cout << "The lowest score is: " << min << endl;
		cout << "The average score is: " << avg << endl;
		cout << endl;
	}
	else
	{
			cout << "There is no scores.\n";

	}
}

bool is_palindrome(string sentence)
{
	string input1, input2;

	input1 = "";
	input2 = "";
	getline(cin, sentence);
	
		cout << "\nEnter a sentence: ";
		getline(cin, sentence);

		for (int i = 0; i < sentence.size(); i++)
		{
			if (isalpha(sentence.at(i)))
			{
				input1 = input1 + (char)tolower(sentence.at(i));
			}
		}

		for (int i = sentence.size() - 1; i >= 0; i--)
		{
			if (isalpha(sentence.at(i)))
				input2 = input2 + (char)tolower(sentence.at(i));
		}

		if (input1 == input2)
		{
			cout << "\"" << sentence << "\" is a palindrome\n" << endl;
		}
		else
		{
			cout << "\"" << sentence << "\" is not a palindrome\n" << endl;
		}
	return 0;
}

int main()
{
	string sentence; 
	vector<int>v;
	char choice;
	do
	{
		v.clear();
		get_scores(v);
		print_stats(v);
		cout << "Do you want to try another set of scores? Y/N: ";
		cin >> choice;
		cout << endl;

		if (choice == 'n' || choice == 'N')
		{
			do
			{
				is_palindrome(sentence);
				cout << "Do you want to try another sentence? Y/N: ";
				cin >> choice;

			} while (choice == 'y' || choice == 'Y');
		}
	} while (choice == 'y' || choice == 'Y');

	cout << "Program ended with exit code: 0\n";
		exit(0);
}