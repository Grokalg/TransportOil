#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct tube
{
	double length = 0;
	double diameter = 0;
	string condition = "Труба ипсравна";
	bool saved = true;
	bool created = false;
	tube() {}
};

struct cs
{
	int rooms = 0;
	int active_rooms = 0;
	int efficiency = 0;
	bool saved = true;
	bool created = false;
	cs() {}
};

void CreateTube(tube& new_tube)
{
	double length, diameter;
	cout << "Введите длину: ";
	cin >> length;
	if (length <= 0)
	{
		cout << "Длина трубы не может быть отрицательной или 0. Введите данные повторно:\n";
		cin >> length;
	}
	cout << "Введите диаметр: ";
	cin >> diameter;
	if (diameter == 0)
	{
		cout << "Диаметр трубы не может составлять 0 м. Введите данные повторно:\n";
		cin >> diameter;
	}
	cout << "Труба исправна\n\n";
	new_tube.length = length;
	new_tube.diameter = diameter;
	new_tube.condition = "Труба исправна";
	new_tube.saved = false;
	new_tube.created = true;
}

void CreateStation(cs& new_cs)
{
	int rooms, active_rooms, efficiency;
	cout << "Укажите количество цехов: ";
	cin >> rooms;
	cout << "Укажите количество работающих цехов: ";
	cin >> active_rooms;
	if (active_rooms > rooms)
	{
		cout << "Колличество работающих цехов не может превыщать колличество всего цехов на КС. Введите число работающих цехов:\n";
		cin >> active_rooms;
	}
	cout << "Введите значение эффективности: ";
	cin >> efficiency;
	new_cs.rooms = rooms;
	new_cs.active_rooms = active_rooms;
	new_cs.efficiency = efficiency;
	new_cs.saved = false;
	new_cs.created = true;
}

void ViewAllObjects(tube& new_tube, cs& new_cs)
{
	if (new_tube.created == true)
	{
		cout << "Характеристики трубы:\n";
		cout << "Длина трубы: " << new_tube.length << endl;
		cout << "Диаметр трубы: " << new_tube.diameter << endl;
		cout << "Состояние: " << new_tube.condition << "\n\n";
	}
	else
	{
		cout << "Труба ещё не создана.\n";
	}
	if (new_cs.created == true)
	{
		cout << "Характеристики КС:\n";
		cout << "Всего цехов: " << new_cs.rooms << endl;
		cout << "Цехи в работе: " << new_cs.active_rooms << endl;
		cout << "Эффективность: " << new_cs.efficiency << endl;
	}
	else
	{
		cout << "КС ещё не создана.\n";
	}
}

void EditTube(tube& new_tube)
{
	if (new_tube.created == true)
	{
		cout << "------------ Редактирование Трубы ------------\n";
		double length, diameter;
		int condition;
		cout << "Введите новое значение длины:\n";
		cin >> length;
		cout << "Введите новое значение диаметра:\n";
		cin >> diameter;
		cout << "Введите значение состояния:\n";
		cout << "Труба исправна<1>   Труба в ремонте<2>\n";
		cin >> condition;
		new_tube.length = length;
		new_tube.diameter = diameter;
		if (condition == 1)
		{
			new_tube.condition = "Труба исправна";
		}
		else
		{
			new_tube.condition = "Труба в ремонте";
		}
		new_tube.saved = false;
	}
	else
	{
		cout << "Труба ещё не создана.\n";
	}
}

void EditStation(cs& new_cs)
{
	if (new_cs.created == true)
	{
		int rooms, active_rooms, efficiency;
		cout << "------------ Редактирование КС ------------\n";
		cout << "Укажите количество цехов: ";
		cin >> rooms;
		cout << "Укажите количество работающих цехов: ";
		cin >> active_rooms;
		if (active_rooms > rooms)
		{
			cout << "Колличество работающих цехов не может превышать колличество всего цехов на КС. Введите число работающих цехов:\n";
			cin >> active_rooms;
		}
		cout << "Введите значение эффективности: ";
		cin >> efficiency;
		new_cs.rooms = rooms;
		new_cs.active_rooms = active_rooms;
		new_cs.efficiency = efficiency;
		new_cs.saved = false;
	}
	else
	{
		cout << "КС ещё не создана.\n";
	}
}

void Save(tube& new_tube, cs& new_cs)
{
	if (new_tube.saved == false)
	{
		int id = 0;
		string current_word, line;
		ifstream in("Tubes.txt");
		if (in.is_open())
		{
			while (in >> current_word)
			{
				if (current_word == "Труба")
				{
					getline(in, line);
					if (line != " исправна" and line != " в ремонте")
					{
						id++;
					}
				}
			}
		}
		in.close();
		id += 1;
		ofstream out("Tubes.txt", ios::app);
		if (out.is_open())
		{
			out << "#####################" << endl;
			out << "Труба номер: " << id << endl;
			out << "Длина: " << new_tube.length << endl;
			out << "Диаметр: " << new_tube.diameter << endl;
			out << "Труба исправна" << endl;
		}
		out.close();
		new_tube.saved = true;
	}
	if (new_cs.saved == false)
	{
		int id = 0;
		string current_word, line;
		ifstream in("CS.txt");
		if (in.is_open())
		{
			while (in >> current_word)
			{
				if (current_word == "Станция:")
				{
					id++;
				}
			}
		}
		in.close();
		id += 1;
		ofstream out("CS.txt", ios::app);
		if (out.is_open())
		{
			out << "#####################" << endl;
			out << "Станция: " << id << endl;
			out << "Всего цехов: " << new_cs.rooms << endl;
			out << "Цехов в работе: " << new_cs.active_rooms << endl;
			out << "Эффективность: " << new_cs.efficiency <<endl;
		}
		out.close();
		new_cs.saved = true;
	}
}

void Download()
{
	cout << "--------------- Трубы ---------------\n";
	string line;
	ifstream in("Tubes.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	in.close();
	cout << "--------------- КС ---------------\n";
	ifstream inr("CS.txt");
	if (inr.is_open())
	{
		while (getline(inr, line))
		{
			cout << line << endl;
		}
	}
	inr.close();
}

int Menu(tube& new_tube, cs& new_cs)
{
	int x;
	setlocale(0, "");
	cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
	cin >> x;
	switch (x) 
	{
		case 1:
			system("cls");
			CreateTube(new_tube);
			return 1;
			break;
		case 2:
			system("cls");
			CreateStation(new_cs);
			return 1;
			break;
		case 3:
			system("cls");
			ViewAllObjects(new_tube, new_cs);
			return 1;
			break;
		case 4:
			system("cls");
			EditTube(new_tube);
			return 1;
			break;
		case 5:
			system("cls");
			EditStation(new_cs);
			return 1;
			break;
		case 6:
			system("cls");
			Save(new_tube, new_cs);
			return 1;
			break;
		case 7:
			system("cls");
			Download();
			return 1;
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Введенные данные не корректны. Пожалуйста, укажите номер, интересующего вас пункта.\n";
	}
}


int main()
{
	tube new_tube;
	cs new_cs;
	for (;;)
	{
		if (Menu(new_tube, new_cs) == 0)
		{
			break;
		}
	}
	return 0;
}