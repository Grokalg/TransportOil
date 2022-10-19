#include "CTube.h"
#include "utils.h"
#include <iostream>

using namespace std;

void CreateTube(tube& new_tube)
{
	cout << "Введите длину в метрах (используйте <.>): ";
	new_tube.length = UserInputParameter();
	cout << "Введите диаметр в метрах (используйте <.>): ";
	new_tube.diameter = UserInputParameter();
	cout << "Труба исправна\n\n";
	new_tube.condition = 1;
}

void EditTube(tube& new_tube)
{
	if (new_tube.length == 0)
	{
		cout << "Труба еще не создана\n";
	}
	else
	{
		cout << "------------ Редактирование Трубы ------------\n";
		cout << "Введите значение состояния:\n";
		cout << "<1> - Труба исправна  <0> - Труба в ремонте\n";
		switch (CorrectChoice())
		{
		case 1:
			new_tube.condition = 1;
			break;
		case 0:
			new_tube.condition = 0;
			break;
		default:
			cout << "Введенные данные не корректны.\n";
			break;
		}
	}
}