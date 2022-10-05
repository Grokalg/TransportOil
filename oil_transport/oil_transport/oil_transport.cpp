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

bool IsDoubleNumber(string str)
{
	int i;
	if (str[0] != ',' and str[str.length()-1] != ',')
	{
		for (i = 0; i < str.length(); i++)
		{
			if (isdigit(str[i]) or str[i] == ',')
			{
				continue;
			}
			else
			{
				return false;
				break;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool IsNumber(string str)
{
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

string CommaSubstitution(string str)
{
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			str[i] = ',';
		}
	}
	return str;
}

double UserInputDouble()
{
	string str;
	while (true)
	{
		cin >> str;
		if (!IsDoubleNumber(str))
		{
			cout << "Введенные данные не корректны.\n";
			continue;
		}
		break;
	}
	return stod(str);
}

int UserInputInt()
{
	//int rooms;
	//do
	//{
	//	cin.clear();
	//	cin.ignore();
	//	cin >> rooms;
	//} while (cin.fail());
	//return rooms;
	string str;
	while (true)
	{
		cin >> str;
		if (!IsNumber(str))
		{
			cout << "Введенные данные не корректны.\n";
			continue;
		}
		break;
	}
	return(stoi(str));
}

int InputActiveRooms(cs& new_cs)
{
	string str;
	int active_rooms;
	while (true)
	{
		cin >> str;
		if (IsNumber(str))
		{
			active_rooms = stoi(str);
			if (stoi(str) > new_cs.rooms)
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
	return active_rooms;
}

int InputEfficiency()
{
	string str;
	int efficiency;
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
	return efficiency;
}

void TubeInput(tube& new_tube)
{
	double diameter, length;
	cout << "Введите длину в метрах (используйте <,>): ";
	length = UserInputDouble();
	cout << "Введите диаметр в метрах (используйте <,>): ";
	diameter = UserInputDouble();
	cout << "Труба исправна\n\n";
	new_tube.length = length;
	new_tube.diameter = diameter;
	new_tube.condition = "Труба исправна";
	new_tube.saved = false;
	new_tube.created = true;
}

void CsInput(cs& new_cs)
{
	cout << "Укажите количество цехов: ";
	new_cs.rooms = UserInputInt();
	cout << "Укажите количество работающих цехов: ";
	new_cs.active_rooms = InputActiveRooms(new_cs);
	cout << "Введите значение эффективности (от 1 до 5): ";
	new_cs.efficiency = InputEfficiency();
	new_cs.saved = false;
	new_cs.created = true;
}

void TubeOverwriting(tube& new_tube)
{
	for (;;)
	{
		string str;
		int user_choice;
		cout << "Вы точно хотите перезаписать трубу?\n";
		cout << "Выберете: <0>, если не хотите перезаписывать,\n";
		cout << "          <1>, если хотите перезаписать\n";
		cin >> str;
		if (IsNumber(str))
		{
			user_choice = stoi(str);
			switch (user_choice)
			{
			case 1:
				TubeInput(new_tube);
				break;
			case 0:
				break;
			default:
				cout << "Введенные данные не корректны.\n";
				break;
			}
			break;
		}
		else
		{
			cout << "Введенные данные не корректны.\n";
		}
	}
}

void CsOverwriting(cs& new_cs)
{
	for (;;)
	{
		string str;
		int user_choice;
		cout << "Вы точно хотите перезаписать КС?\n";
		cout << "Выберете: <0>, если не хотите перезаписывать,\n";
		cout << "          <1>, если хотите перезаписать\n";
		cin >> str;
		if (IsNumber(str))
		{
			user_choice = stoi(str);
			switch (user_choice)
			{
			case 1:
				CsInput(new_cs);
				break;
			case 0:
				break;
			default:
				cout << "Введенные данные не корректны.\n";
				break;
			}
			break;
		}
		else
		{
			cout << "Введенные данные не корректны.\n";
		}
	}
}

int CorrectChoice()
{
	int user_choice;
	do
	{
		cin.clear();
		cin.ignore();
		cin >> user_choice;
	} while (cin.fail() || user_choice < 0 || user_choice > 1);
	return user_choice;
}

void CheckTransformationError(cs& new_cs, int rooms, int active_rooms)
{
	if (active_rooms > rooms)
	{
		cout << "Колличество работающих цехов не может превышать колличество всего цехов на КС.\n";
		cout << "Последние изменения не будут применены.\n\n";
		new_cs.active_rooms--;
	}
	if (active_rooms < 0)
	{
		cout << "Колличество работающих цехов не может быть отрицательным.\n";
		cout << "Последние изменения не будут применены.\n\n";
		new_cs.active_rooms++;
	}
}

void CreatedCheck(tube new_tube, cs new_cs)
{
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

void StatusMessage(tube& new_tube, cs& new_cs, int error_flag)
{
	if (error_flag == 1)
	{
		cout << "Ошибка при чтении файла. Проверьте корректность данных.\n";
	}
	else
	{
		cout << "--------------- Труба ---------------\n";
		cout << "Длина: " << new_tube.length << endl;
		cout << "Диаметр: " << new_tube.diameter << endl;
		cout << "Состояние: " << new_tube.condition << endl;
		new_tube.saved = true;
		new_tube.created = true;
		cout << "---------------- КС -----------------\n";
		cout << "Всего цехов: " << new_cs.rooms << endl;
		cout << "Цехов в работе: " << new_cs.active_rooms << endl;
		cout << "Эффективность: " << new_cs.efficiency << "\n\n";
		new_cs.saved = true;
		new_cs.created = true;
	}
}

void TubeDownload(tube& new_tube, int& error_flag)
{
	string line, current_word;
	ifstream in("Tubes.txt");
	if (in.is_open())
	{
		while (in >> current_word)
		{
			if (current_word == "Длина:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end()); //https://ru.stackoverflow.com/questions/1071460/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D1%80%D0%BE%D0%B1%D0%B5%D0%BB%D0%BE%D0%B2-%D0%B8%D0%B7-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8
				line = CommaSubstitution(line);
				if (IsDoubleNumber(line) and stod(line) > 0)
				{
					new_tube.length = stod(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "Диаметр:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				line = CommaSubstitution(line);
				if (IsDoubleNumber(line) and stod(line) > 0)
				{
					new_tube.diameter = stod(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "Труба")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				if (line == "исправна" or line == "в ремонте")
				{
					new_tube.condition = "Труба " + line;
				}
				else
				{
					error_flag = 1;
				}
			}
		}
	}
	in.close();
}

void CsDownload(cs& new_cs, int& error_flag)
{
	string line, current_word;
	int rooms;
	ifstream inr("CS.txt");
	if (inr.is_open())
	{
		while (inr >> current_word)
		{
			if (current_word == "цехов:")
			{
				getline(inr, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end()); //https://ru.stackoverflow.com/questions/1071460/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D1%80%D0%BE%D0%B1%D0%B5%D0%BB%D0%BE%D0%B2-%D0%B8%D0%B7-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8
				if (IsNumber(line) and stoi(line) > 0)
				{
					rooms = stoi(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "работе:")
			{
				getline(inr, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				if (IsNumber(line))
				{
					new_cs.active_rooms = stoi(line);
					new_cs.rooms = rooms;
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "Эффективность:")
			{
				getline(inr, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				if (IsNumber(line) and stoi(line) <= 5 and stoi(line) > 0)
				{
					new_cs.efficiency = stoi(line);
				}
				else
				{
					error_flag = 1;
				}
			}
		}
	}
	inr.close();
}

void CreateTube(tube& new_tube)
{
	if (new_tube.created == true)
	{
		TubeOverwriting(new_tube);		
	}
	else
	{
		TubeInput(new_tube);
	}
}

void CreateStation(cs& new_cs)
{
	if (new_cs.created == true)
	{
		CsOverwriting(new_cs);
	}
	else
	{
		CsInput(new_cs);
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
		int user_choice;
		cout << "------------ Редактирование Трубы ------------\n";
		cout << "Введите значение состояния:\n";
		cout << "<0> - Труба исправна  <1> - Труба в ремонте\n";
		user_choice = CorrectChoice();
		switch (user_choice)
		{
		case 1:
			new_tube.condition = "Труба в ремонте";
			new_tube.saved = false;
			break;
		case 0:
			new_tube.condition = "Труба исправна";
			new_tube.saved = false;
			break;
		default:
			cout << "Введенные данные не корректны.\n";
			break;
		}
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
		int user_choice;
		cout << "------------ Редактирование КС ------------\n";
		cout << "Колличество работающих цехов на данный момент: " << new_cs.active_rooms << endl;
		cout << "<0> - Убрать активный цех, <1> - Добавить активный цех\n";
		user_choice = CorrectChoice();
		switch (user_choice)
		{
		case 1:
			new_cs.active_rooms++;
			CheckTransformationError(new_cs, new_cs.rooms, new_cs.active_rooms);
			cout << "Колл-во работающих цехов: " << new_cs.active_rooms << endl;
			break;
		case 0:
			new_cs.active_rooms--;
			CheckTransformationError(new_cs, new_cs.rooms, new_cs.active_rooms);
			cout << "Колл-во работающих цехов: " << new_cs.active_rooms << endl;
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "КС ещё не создана.\n";
	}
}

void Save(tube& new_tube, cs& new_cs)
{
	CreatedCheck(new_tube, new_cs);
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
}

void Download(tube& new_tube, cs& new_cs)
{
	int error_flag;
	TubeDownload(new_tube, error_flag);
	CsDownload(new_cs, error_flag);
	StatusMessage(new_tube, new_cs, error_flag);
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
		system("cls");
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
	else
	{
		cout << "Введенные данные не корректны. Пожалуйста, укажите номер интересующего вас пункта.\n\n";
		return 1;
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