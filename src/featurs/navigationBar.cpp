#include <iostream>

#include "console.h"
#include "taskManager.h"

using namespace std;

bool checkChoiceInput(char ch, const vector<char> &validChoices)
{
	for (char validCh : validChoices)
		if (ch == validCh)
			return true;

	return false;
}

void showMenuTask()
{
	cout << "Tasks:";
	cout << "\n1 - Task 1";
	cout << "\n2 - Task 2";
	newLine();
	cout << "\nq - Quit";
	newLine();
	cout << "\nYour choice: ";
}

void chooseTask()
{
	clearConsole();
	char ch;
	vector<char> validChoices = {'1', '2', 'q'};

	while (true)
	{
		showMenuTask();
		cin >> ch;
		bool selected = checkChoiceInput(ch, validChoices);

		if (!selected)
		{
			clearConsole();
			cout << "Invalid choice. Please try again.\n";
			pauseConsole();
			continue;
		}

		clearConsole();
		cout << "Task" << ch << " selected\n";
		newLine();

		switch (ch)
		{
		case '1':
			task_01();
			break;
		case '2':
			task_02();
			break;
		case 'q':
			cout << "Goodbye!\n\n";
			return;
		}

		pauseConsole();
	}
}
