#include "utils.h"
#include <iostream>
#include "CCs.h"

using namespace std;

string InputName()
{
	string name;
	cin >> name;
	while (cin.fail() || cin.peek() != '\n')
	{
		cout << "¬веденные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> name;
	}
	return name;
}

double utils::UserInputParameter()
{
	double parameter;
	cin >> parameter;
	while (cin.fail() || cin.peek() != '\n' || parameter <= 0)
	{
		cout << "¬веденные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> parameter;
	}
	return parameter;
}

int utils::CorrectChoice()
{
	int user_choice;
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> user_choice;
	} while (cin.fail() || user_choice < 0 || user_choice > 1);
	return user_choice;
}

int utils::InputActiveRooms(cs& new_cs)
{
	int active_rooms;
	cin >> active_rooms;
	while (cin.fail() || cin.peek() != '\n' || active_rooms > new_cs.rooms || active_rooms < 0)
	{
		cout << "¬веденные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> active_rooms;
	}
	return active_rooms;
}

int utils::InputEfficiency()
{
	int efficiency;
	cin >> efficiency;
	while (cin.fail() || cin.peek() != '\n' || efficiency <= 0 || efficiency > 5)
	{
		cout << "¬веденные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> efficiency;
	}
	return efficiency;
}
