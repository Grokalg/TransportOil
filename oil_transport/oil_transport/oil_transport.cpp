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
	if (new_tube.created == true)
	{
		int user_choice;
		cout << "Вы точно хотите перезаписать трубу?\n";
		cout << "Выберете: <0>, если не хотите перезаписывать трубу,\n";
		cout << "          <1>, если хотите перезаписать\n";
		cin >> user_choice;
		if (user_choice == 1)
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
	}
	else
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
}

void CreateStation(cs& new_cs)
{
	if (new_cs.created == true)
	{
		int user_choice;
		cout << "Вы точно хотите перезаписать КС?\n";
		cout << "Выберете: <0>, если не хотите перезаписывать трубу,\n";
		cout << "          <1>, если хотите перезаписать\n";
		cin >> user_choice;
		if (user_choice == 1)
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
	}
	else
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
		cout << "Эффективность: " << new_cs.efficiency << "\n\n";
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
		int user_choice;
		cout << "Введите значение состояния:\n";
		cout << "<0> - Труба исправна  <1> - Труба в ремонте\n";
		cin >> user_choice;
		if (user_choice == 0)
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
		int user_choice = 3;
		cout << "------------ Редактирование КС ------------\n";
		cout << "Колличество работающих цехов на данный момент: " << new_cs.active_rooms << endl;
		cout << "<0> - Убрать активный цех, <1> - Добавить активный цех, <2> - Закончить редактирование\n";
		for (;;)
		{
			cin >> user_choice;
			if (user_choice == 0)
			{
				new_cs.active_rooms--;
			}
			if (user_choice == 1)
			{
				new_cs.active_rooms++;
			}
			if (user_choice == 2)
			{
				break;
			}
			if (new_cs.active_rooms > new_cs.rooms)
			{
				cout << "Колличество работающих цехов не может превышать колличество всего цехов на КС.\n";
				cout << "Последние изменения не будут применены.\n\n";
				new_cs.active_rooms--;
				break;
			}
			if (new_cs.active_rooms < 0)
			{
				cout << "Колличество работающих цехов не может быть отрицательным.\n";
				cout << "Последние изменения не будут применены.\n\n";
				new_cs.active_rooms++;
				break;
			}
		}
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
		ofstream out("Tubes.txt");
		if (out.is_open())
		{
			out << "#####################" << endl;
			out << "Длина: " << new_tube.length << endl;
			out << "Диаметр: " << new_tube.diameter << endl;
			out << "Труба исправна" << endl;
		}
		out.close();
		new_tube.saved = true;
	}
	if (new_cs.saved == false)
	{
		ofstream out("CS.txt");
		if (out.is_open())
		{
			out << "#####################" << endl;
			out << "Всего цехов: " << new_cs.rooms << endl;
			out << "Цехов в работе: " << new_cs.active_rooms << endl;
			out << "Эффективность: " << new_cs.efficiency <<endl;
		}
		out.close();
		new_cs.saved = true;
	}
}

void Download(tube& new_tube, cs& new_cs)
{
	cout << "--------------- Труба ---------------\n";
	string line, current_word;
	ifstream in("Tubes.txt");
	if (in.is_open())
	{
		while (in>>current_word)
		{
			if (current_word == "Длина:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end()); //https://ru.stackoverflow.com/questions/1071460/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D1%80%D0%BE%D0%B1%D0%B5%D0%BB%D0%BE%D0%B2-%D0%B8%D0%B7-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8
				new_tube.length = stod(line); //Преобразование строки в число https://arduinoplus.ru/preobrazovanie-stroki-string-v-czeloe-chislo-int-v-c/
			}
			if (current_word == "Диаметр:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				new_tube.diameter = stod(line);
			}
			if (current_word == "Труба")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				new_tube.condition = "Труба "+ line;
			}			
		}
	}
	in.close();
	new_tube.saved = true;
	new_tube.created = true;
	cout << "Длина: " << new_tube.length << endl;
	cout << "Диаметр: " << new_tube.diameter << endl;
	cout << "Состояние: " << new_tube.condition << endl;
	cout << "---------------- КС -----------------\n";
	ifstream inr("CS.txt");
	if (inr.is_open())
	{
		while (inr >> current_word)
		{
			if (current_word == "цехов:")
			{
				getline(inr, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end()); //https://ru.stackoverflow.com/questions/1071460/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D1%80%D0%BE%D0%B1%D0%B5%D0%BB%D0%BE%D0%B2-%D0%B8%D0%B7-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8
				new_cs.rooms = stoi(line); //Преобразование строки в число https://arduinoplus.ru/preobrazovanie-stroki-string-v-czeloe-chislo-int-v-c/
			}
			if (current_word == "работе:")
			{
				getline(inr, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				new_cs.active_rooms = stoi(line);
			}
			if (current_word == "Эффективность:")
			{
				getline(inr, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				new_cs.efficiency = stoi(line);
			}
		}
	}
	inr.close();
	new_cs.saved = true;
	new_cs.created = true;
	cout << "Всего цехов: " << new_cs.rooms << endl;
	cout << "Цехов в работе: " << new_cs.active_rooms << endl;
	cout << "Эффективность: " << new_cs.efficiency << "\n\n";
}

int Menu(tube& new_tube, cs& new_cs)
{
	int user_choice;
	cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
	cin >> user_choice;
	switch (user_choice)
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
			Download(new_tube, new_cs);
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
	setlocale(0, "");
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