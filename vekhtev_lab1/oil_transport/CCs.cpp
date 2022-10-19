#include "CCs.h"
#include "utils.h"
#include <iostream>

void CreateStation(cs& new_cs)
{
	cout << "Введите название: ";
	getline(cin >> ws, new_cs.name);
	cout << "Укажите количество цехов: ";
	new_cs.rooms = InputRooms();
	cout << "Укажите количество работающих цехов: ";
	new_cs.active_rooms = InputActiveRooms(new_cs);
	cout << "Введите значение эффективности (от 1 до 5): ";
	new_cs.efficiency = InputEfficiency();
}

void EditStation(cs& new_cs)
{
	if (new_cs.rooms == 0)
	{
		cout << "КС еще не создана\n";
	}
	else
	{
		cout << "------------ Редактирование КС ------------\n";
		cout << "Количество работающих цехов на данный момент: " << new_cs.active_rooms << endl;
		cout << "<0> - Убрать активный цех, <1> - Добавить активный цех\n";
		switch (CorrectChoice())
		{
		case 1:
			if (IsPosibleTransformationAdd(new_cs))
			{
				new_cs.active_rooms++;
				cout << "Кол-во работающих цехов: " << new_cs.active_rooms << endl;
			}
			break;
		case 0:
			if (IsPosibleTransformationSub(new_cs))
			{
				new_cs.active_rooms--;
				cout << "Кол-во работающих цехов: " << new_cs.active_rooms << endl;
			}
			break;
		default:
			break;
		}
	}
}