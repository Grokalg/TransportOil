#include <iostream>
#include <fstream>
#include <string>
#include <cctype>   // для функции isdigit

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

bool IsNumber(string str)
{
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
			break;
		}
	}
}

int CreateTube(tube& new_tube)
{
	if (new_tube.created == true)
	{
		string str;
		int user_choice;
		cout << "Вы точно хотите перезаписать трубу?\n";
		cout << "Выберете: <0>, если не хотите перезаписывать трубу,\n";
		cout << "          <1>, если хотите перезаписать\n";
		cin >> str;
		if (IsNumber(str))
		{
			user_choice = stoi(str);
			switch (user_choice)
			{
			case 1:
				float diameter, length;
				while (true)
				{
					cout << "Введите длину: ";
					cin >> str;
					if (IsNumber(str))
					{
						length = stof(str);
						if (length <= 0)
						{
							cout << "Длина трубы не может быть отрицательной или 0. Введите данные повторно.\n";
							continue;
						}
					}
					else
					{
						cout << "Введенные данные не корректны.\n";
						continue;
					}
					break;
				}
				while (true)
				{
					cout << "Введите диаметр: ";
					cin >> str;
					if (IsNumber(str))
					{
						diameter = stof(str);
						if (diameter == 0)
						{
							cout << "Диаметр трубы не может составлять 0 м. Введите данные повторно:\n";
							continue;
						}
					}
					else
					{
						cout << "Введенные данные не корректны.\n";
						continue;
					}
					break;
				}				
				cout << "Труба исправна\n\n";
				new_tube.length = length;
				new_tube.diameter = diameter;
				new_tube.condition = "Труба исправна";
				new_tube.saved = false;
				new_tube.created = true;
				return 0;
			case 0:
				return 0;
			default:
				cout << "Введенные данные не корректны.\n";
				break;
			}
		}
		else
		{
			cout << "Введенные данные не корректны.\n";
		}
	}
	else
	{
		string str;
		float diameter, length;
		while (true)
		{
			cout << "Введите длину: ";
			cin >> str;
			if (IsNumber(str))
			{
				length = stof(str);
				if (length <= 0)
				{
					cout << "Длина трубы не может быть отрицательной или 0. Введите данные повторно.\n";
					continue;
				}
			}
			else
			{
				cout << "Введенные данные не корректны.\n";
				continue;
			}
			break;
		}
		while (true)
		{
			cout << "Введите диаметр: ";
			cin >> str;
			if (IsNumber(str))
			{
				diameter = stof(str);
				if (diameter == 0)
				{
					cout << "Диаметр трубы не может составлять 0 м. Введите данные повторно:\n";
					continue;
				}
			}
			else
			{
				cout << "Введенные данные не корректны.\n";
				continue;
			}
			break;
		}
		cout << "Труба исправна\n\n";
		new_tube.length = length;
		new_tube.diameter = diameter;
		new_tube.condition = "Труба исправна";
		new_tube.saved = false;
		new_tube.created = true;
		return 0;
	}
}

int CreateStation(cs& new_cs)
{
	if (new_cs.created == true)
	{
		string str;
		int user_choice;
		cout << "Вы точно хотите перезаписать КС?\n";
		cout << "Выберете: <0>, если не хотите перезаписывать трубу,\n";
		cout << "          <1>, если хотите перезаписать\n";
		cin >> str;
		if (IsNumber(str))
		{
			user_choice = stoi(str);
			switch (user_choice)
			{
			case 1:
				int rooms, active_rooms, efficiency;
				while (true)
				{
					cout << "Укажите количество цехов: ";
					cin >> str;
					if (IsNumber(str))
					{
						rooms = stoi(str);
						if (rooms <= 0)
						{
							cout << "Колличество цехов не может быть отрицательной или 0. Введите данные повторно.\n";
							continue;
						}
					}
					else
					{
						cout << "Введенные данные не корректны.\n";
						continue;
					}
					break;
				}
				while (true)
				{
					cout << "Укажите количество работающих цехов: ";
					cin >> str;
					if (IsNumber(str))
					{
						active_rooms = stoi(str);
						if (active_rooms > rooms)
						{
							cout << "Колличество работающих цехов не может превыщать колличество всего цехов на КС. Введите число работающих цехов:\n";
							continue;
						}
					}
					else
					{
						cout << "Введенные данные не корректны.\n";
						continue;
					}
					break;
				}
				while (true)
				{
					cout << "Введите значение эффективности (от 1 до 5): ";
					cin >> str;
					if (IsNumber(str))
					{
						efficiency = stoi(str);
						if (efficiency <= 0 or efficiency > 5)
						{
							cout << "Введенные данные не корректны. Эффективность - число от 1 до 5.\n";
							cout << "Введите число работающих цехов : \n";
							continue;
						}
					}
					else
					{
						cout << "Введенные данные не корректны.\n";
						continue;
					}
					break;
				}
				new_cs.rooms = rooms;
				new_cs.active_rooms = active_rooms;
				new_cs.efficiency = efficiency;
				new_cs.saved = false;
				new_cs.created = true;
				return 0;
			case 0:
				return 0;
			default:
				cout << "Введенные данные не корректны.\n";
				break;
			}
		}
	}
	else
	{
		string str;
		int rooms, active_rooms, efficiency;
		while (true)
		{
			cout << "Укажите количество цехов: ";
			cin >> str;
			if (IsNumber(str))
			{
				rooms = stoi(str);
				if (rooms <= 0)
				{
					cout << "Колличество цехов не может быть отрицательной или 0. Введите данные повторно.\n";
					continue;
				}
			}
			else
			{
				cout << "Введенные данные не корректны.\n";
				continue;
			}
			break;
		}
		while (true)
		{
			cout << "Укажите количество работающих цехов: ";
			cin >> str;
			if (IsNumber(str))
			{
				active_rooms = stoi(str);
				if (active_rooms > rooms)
				{
					cout << "Колличество работающих цехов не может превыщать колличество всего цехов на КС. Введите число работающих цехов:\n";
					continue;
				}
			}
			else
			{
				cout << "Введенные данные не корректны.\n";
				continue;
			}
			break;
		}
		while (true)
		{
			cout << "Введите значение эффективности (от 1 до 5): ";
			cin >> str;
			if (IsNumber(str))
			{
				efficiency = stoi(str);
				if (efficiency <= 0 or efficiency > 5)
				{
					cout << "Введенные данные не корректны. Эффективность - число от 1 до 5.\n";
					cout << "Введите число работающих цехов : \n";
					continue;
				}
			}
			else
			{
				cout << "Введенные данные не корректны.\n";
				continue;
			}
			break;
		}
		new_cs.rooms = rooms;
		new_cs.active_rooms = active_rooms;
		new_cs.efficiency = efficiency;
		new_cs.saved = false;
		new_cs.created = true;
		return 0;
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

int EditTube(tube& new_tube)
{
	if (new_tube.created == true)
	{
		int user_choice;
		string str;
		cout << "Введите значение состояния:\n";
		cout << "<0> - Труба исправна  <1> - Труба в ремонте\n";
		cin >> str;
		if (IsNumber(str))
		{
			user_choice = stoi(str);
			switch (user_choice)
			{
			case 1:
				new_tube.condition = "Труба в ремонте";
				new_tube.saved = false;
				return 0;
			case 0:
				new_tube.condition = "Труба исправна";
				new_tube.saved = false;
				return 0;
			default:
				cout << "Введенные данные не корректны.\n";
				break;
			}
		}
		else
		{
			cout << "Введенные данные не корректны.\n";
		}
	}
	else
	{
		cout << "Труба ещё не создана.\n";
		return 0;
	}
}

void EditStation(cs& new_cs)
{
	if (new_cs.created == true)
	{
		string str;
		int user_choice = 3;
		cout << "------------ Редактирование КС ------------\n";
		cout << "Колличество работающих цехов на данный момент: " << new_cs.active_rooms << endl;
		cout << "<0> - Убрать активный цех, <1> - Добавить активный цех, <2> - Закончить редактирование\n";
		for (;;)
		{
			cin >> str;
			if (IsNumber(str) and stoi(str)>=0 and stoi(str)<=2)
			{
				user_choice = stoi(str);
				if (user_choice == 0)
				{
					new_cs.active_rooms--;
					cout << "Колл-во работающих цехов: " << new_cs.active_rooms << endl;
				}
				if (user_choice == 1)
				{
					new_cs.active_rooms++;
					cout << "Колл-во работающих цехов: " << new_cs.active_rooms << endl;
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
					cout << "Колл-во работающих цехов: " << new_cs.active_rooms << endl;
					break;
				}
				if (new_cs.active_rooms < 0)
				{
					cout << "Колличество работающих цехов не может быть отрицательным.\n";
					cout << "Последние изменения не будут применены.\n\n";
					new_cs.active_rooms++;
					cout << "Колл-во работающих цехов: " << new_cs.active_rooms << endl;
					break;
				}
			}
			else 
			{
				cout << "Введенные данные не корректны.\n";
			}
		}
		cout << "Колличество работающих цехов на данный момент: " << new_cs.active_rooms << endl;
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
		cout << "Данные по трубе сохранены\n\n";
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
		cout << "Данные по КС сохранены\n\n";
	}
	if (new_tube.created == false)
	{
		cout << "Вы не создали ни одну трубу.\n";
		cout << "Перейдите в пункт <1> главного меню для создания, или загрузите данные из файла\n\n";
	}
	if (new_cs.created == false)
	{
		cout << "Вы не создали ни одну КС.\n";
		cout << "Перейдите в пункт <2> главного меню для создания, или загрузите данные из файла\n\n";
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
	string str;
	int user_choice = 0;
	cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
	cin >> str;
	if (IsNumber(str))
	{
		user_choice = stoi(str);
		switch (user_choice)
		{
		case 1:
			system("cls");
			for (;;)
			{
				if (CreateTube(new_tube) == 0)
				{
					break;
				}
			}
			return 1;
			break;
		case 2:
			system("cls");
			for (;;)
			{
				if (CreateStation(new_cs) == 0)
				{
					break;
				}
			}
			return 1;
			break;
		case 3:
			system("cls");
			ViewAllObjects(new_tube, new_cs);
			return 1;
			break;
		case 4:
			system("cls"); 
			cout << "------------ Редактирование Трубы ------------\n";
			for (;;)
			{
				if (EditTube(new_tube) == 0)
				{
					break;
				}
			}
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
			cout << "Введенные данные не корректны. Пожалуйста, укажите номер интересующего вас пункта.\n\n";
		}
	}
	else
	{
		cout << "Введенные данные не корректны. Пожалуйста, укажите номер интересующего вас пункта.\n\n";
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