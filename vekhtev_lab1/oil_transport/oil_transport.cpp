#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "CTube.h"
#include "CCs.h"

using namespace std;

int InputRooms()
{
	int rooms;
	cin >> rooms;
	while (cin.fail() || cin.peek() != '\n' || rooms <= 0)
	{
		cout << "Введенные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> rooms;
	}
	return rooms;
}



bool IsCorrectMenuChoice(int user_choice)
{
	if (cin.fail() || cin.peek() != '\n' || user_choice < 0 || user_choice > 7)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Данные не корректны"<<endl;
		return false;
	}
	return true;
}

bool IsPosibleTransformationAdd(cs& new_cs)
{
	if (new_cs.active_rooms > new_cs.rooms)
	{
		cout << "Количество работающих цехов не может превышать колличество всего цехов на КС.\n";
		return false;
	}
	if (new_cs.active_rooms < 0)
	{
		cout << "Количество работающих цехов не может быть отрицательным.\n";
		return false;
	}
}

bool IsPosibleTransformationSub(cs& new_cs)
{
	if (new_cs.active_rooms > new_cs.rooms)
	{
		cout << "Количество работающих цехов не может превышать колличество всего цехов на КС.\n";
		return false;
	}
	if (new_cs.active_rooms <= 0)
	{
		cout << "Количество работающих цехов не может быть отрицательным.\n";
		return false;
	}
}

double ReadValue(ifstream& in)
{
	double parameter = 0;
	if (in.fail() || in.peek() != '\n')
	{
		in >> parameter;
	}
	return parameter;
}

string ReadName(ifstream& in)
{
	string name;
	if (in.fail() || in.peek() != '\n')
	{
		in >> name;
	}
	return name;
}

void ViewAllObjects(tube& new_tube, cs& new_cs)
{
	if (new_tube.length == 0)
	{
		cout << "Труба еще не создана\n";
	}
	else
	{
		cout << "Характеристики трубы:\n";
		cout << "Длина трубы: " << new_tube.length << endl;
		cout << "Диаметр трубы: " << new_tube.diameter << endl;
		cout << "Состояние: " << new_tube.condition << "\n\n";
	}
	if (new_cs.rooms == 0)
	{
		cout << "КС еще не создана\n";
	}
	else
	{
		cout << "Характеристики КС:\n";
		cout << "Название: " << new_cs.name << endl;
		cout << "Всего цехов: " << new_cs.rooms << endl;
		cout << "Цехи в работе: " << new_cs.active_rooms << endl;
		cout << "Эффективность: " << new_cs.efficiency << "\n\n";
	}
}

void Save(tube& new_tube, cs& new_cs)
{
	ofstream out("Data.txt");
	if (new_tube.length == 0)
	{
		cout << "Труба еще не создана\n";
	}
	else
	{
		if (out.is_open())
		{
			out << "Труба" << endl;
			out << new_tube.length << endl;
			out << new_tube.diameter << endl;
			out << new_tube.condition << endl;
		}
		out.close();
		cout << "Данные по трубе сохранены\n\n";
	}
	if (new_cs.rooms == 0)
	{
		cout << "КС еще не создана\n";
	}
	else
	{
		if (out.is_open())
		{
			out << "КС" << endl;
			out << new_cs.name << endl;
			out << new_cs.rooms << endl;
			out << new_cs.active_rooms << endl;
			out << new_cs.efficiency << endl;
		}
		out.close();		
		cout << "Данные по КС сохранены\n\n";
	}
}

void Download(tube& new_tube, cs& new_cs)
{
	string current_word;
	ifstream in("Data.txt");
	if (in.is_open())
	{
		in >> current_word;
		if (current_word == "Труба")
		{
			in >> new_tube.length;
			in >> new_tube.diameter;
			in >> new_tube.condition;
		}
		if (current_word == "КС")
		{
			getline(in >> ws, new_cs.name);
			in >> new_cs.rooms;
			in >> new_cs.active_rooms;
			in >> new_cs.efficiency;
		}
	}
	in.close();
	cout << "Данные загружены\n";
}

void ShowMenu()
{
	cout << "1. Добавить трубу\n";
	cout << "2. Добавить КС\n";
	cout << "3. Просмотр всех объектов\n";
	cout << "4. Редактировать трубу\n";
	cout << "5. Редактировать КС\n";
	cout << "6. Сохранить\n";
	cout << "7. Загрузить\n";
	cout << "0. Выход\n";
}

int Menu(tube& new_tube, cs& new_cs)
{
	int user_choice;
	do { cin >> user_choice; } while (IsCorrectMenuChoice(user_choice) == false);
	switch (user_choice)
	{
	case 1:
		CreateTube(new_tube);
		return 1;
	case 2:
		CreateStation(new_cs);
		return 1;
	case 3:
		ViewAllObjects(new_tube, new_cs);
		return 1;
	case 4:
		EditTube(new_tube);
		return 1;
	case 5:
		EditStation(new_cs);
		return 1;
	case 6:
		Save(new_tube, new_cs);
		return 1;
	case 7:
		Download(new_tube, new_cs);
		return 1;
	case 0:
		return 0;
	default:
		cout << "Введенные данные не корректны. Пожалуйста, укажите номер интересующего вас пункта.\n\n";
		return 1;
	}
}

int main()
{
	setlocale(0, "");
	tube new_tube;
	cs new_cs;
	unordered_map <int, tube> tubes;
	do { ShowMenu(); } while (Menu(new_tube, new_cs) != 0);
}