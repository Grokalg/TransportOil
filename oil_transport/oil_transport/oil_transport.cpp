#include <iostream>
#include <fstream>
#include <string>
#include <cctype>   // для функции isdigit

using namespace std;

struct tube
{
	double length = 0;
	double diameter = 0;
	int condition = 1;
	tube() {}
};

struct cs
{
	int rooms = 0;
	int active_rooms = 0;
	int efficiency = 0;
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

string CommaSubstitution(string& str)
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
	double parameter;
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> parameter;
	} while (cin.fail() || cin.peek() != '\n' || parameter <= 0);
	return parameter;
}

int InputRooms()
{
	int rooms;
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> rooms;
	} while (cin.fail() || cin.peek() != '\n' || rooms < 0);
	return rooms;
}

int InputActiveRooms(cs& new_cs)
{
	int active_rooms;
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> active_rooms;
	} while (cin.fail() || cin.peek() != '\n' || active_rooms > new_cs.rooms || active_rooms <= 0);
	return active_rooms;
}

int InputEfficiency()
{
	int efficiency;
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> efficiency;
	} while (cin.fail() || cin.peek() != '\n' || efficiency <= 0 || efficiency > 5);
	return efficiency;
}

//void TubeInput(tube& new_tube)
//{
//	double diameter, length;
//	cout << "Введите длину в метрах (используйте <,>): ";
//	length = UserInputDouble();
//	cout << "Введите диаметр в метрах (используйте <,>): ";
//	diameter = UserInputDouble();
//	cout << "Труба исправна\n\n";
//	new_tube.length = length;
//	new_tube.diameter = diameter;
//	new_tube.condition = "Труба исправна";
//	new_tube.saved = false;
//	new_tube.created = true;
//}

//void CsInput(cs& new_cs)
//{
//
//}

//void TubeOverwriting(tube& new_tube)
//{
//	for (;;)
//	{
//		string str;
//		int user_choice;
//		cout << "Вы точно хотите перезаписать трубу?\n";
//		cout << "Выберете: <0>, если не хотите перезаписывать,\n";
//		cout << "          <1>, если хотите перезаписать\n";
//		cin >> str;
//		if (IsNumber(str))
//		{
//			user_choice = stoi(str);
//			switch (user_choice)
//			{
//			case 1:
//				TubeInput(new_tube);
//				break;
//			case 0:
//				break;
//			default:
//				cout << "Введенные данные не корректны.\n";
//				break;
//			}
//			break;
//		}
//		else
//		{
//			cout << "Введенные данные не корректны.\n";
//		}
//	}
//}

//void CsOverwriting(cs& new_cs)
//{
//	for (;;)
//	{
//		string str;
//		int user_choice;
//		cout << "Вы точно хотите перезаписать КС?\n";
//		cout << "Выберете: <0>, если не хотите перезаписывать,\n";
//		cout << "          <1>, если хотите перезаписать\n";
//		cin >> str;
//		if (IsNumber(str))
//		{
//			user_choice = stoi(str);
//			switch (user_choice)
//			{
//			case 1:
//				CsInput(new_cs);
//				break;
//			case 0:
//				break;
//			default:
//				cout << "Введенные данные не корректны.\n";
//				break;
//			}
//			break;
//		}
//		else
//		{
//			cout << "Введенные данные не корректны.\n";
//		}
//	}
//}

int CorrectChoice()
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

bool IsCorrectMenuChoice(int& user_choice)
{
	if (cin.fail() || cin.peek() != '\n' || user_choice <= 0 || user_choice > 7)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Данные не корректны"<<endl;
		return false;
	}
	return true;
}

bool IsPosibleTransformation(cs& new_cs)
{
	if (new_cs.active_rooms > new_cs.rooms)
	{
		cout << "Колличество работающих цехов не может превышать колличество всего цехов на КС.\n";
		return false;
	}
	if (new_cs.active_rooms < 0)
	{
		cout << "Колличество работающих цехов не может быть отрицательным.\n";
		return false;
	}
}

//void CreatedCheck(tube new_tube, cs new_cs)
//{
//	if (new_tube.created == false)
//	{
//		cout << "Вы не создали ни одну трубу.\n";
//		cout << "Перейдите в пункт <1> главного меню для создания, или загрузите данные из файла\n\n";
//	}
//	if (new_cs.created == false)
//	{
//		cout << "Вы не создали ни одну КС.\n";
//		cout << "Перейдите в пункт <2> главного меню для создания, или загрузите данные из файла\n\n";
//	}
//}

void InfoMessage(tube& new_tube, cs& new_cs, int error_flag)
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
		cout << "---------------- КС -----------------\n";
		cout << "Всего цехов: " << new_cs.rooms << endl;
		cout << "Цехов в работе: " << new_cs.active_rooms << endl;
		cout << "Эффективность: " << new_cs.efficiency << "\n\n";
	}
}

//void TubeDownload(tube& new_tube, cs& new_cs, int& error_flag)
//{
//	
//}

//void CsDownload(cs& new_cs, int& error_flag)
//{
//	string line, current_word;
//	int rooms;
//	ifstream inr("Tubes.txt");
//	if (inr.is_open())
//	{
//		while (inr >> current_word)
//		{
//			
//		}
//	}
//	inr.close();
//}

void CreateTube(tube& new_tube)
{
	cout << "Введите длину в метрах (используйте <,>): ";
	new_tube.length = UserInputDouble();
	cout << "Введите диаметр в метрах (используйте <,>): ";
	new_tube.diameter = UserInputDouble();
	cout << "Труба исправна\n\n";
	new_tube.condition = 1;
}

void CreateStation(cs& new_cs)
{
	cout << "Укажите количество цехов: ";
	new_cs.rooms = InputRooms();
	cout << "Укажите количество работающих цехов: ";
	new_cs.active_rooms = InputActiveRooms(new_cs);
	cout << "Введите значение эффективности (от 1 до 5): ";
	new_cs.efficiency = InputEfficiency();
}

void ViewAllObjects(tube& new_tube, cs& new_cs)
{
	cout << "Характеристики трубы:\n";
	cout << "Длина трубы: " << new_tube.length << endl;
	cout << "Диаметр трубы: " << new_tube.diameter << endl;
	cout << "Состояние: " << new_tube.condition << "\n\n";
	cout << "Труба ещё не создана.\n";
	cout << "Характеристики КС:\n";
	cout << "Всего цехов: " << new_cs.rooms << endl;
	cout << "Цехи в работе: " << new_cs.active_rooms << endl;
	cout << "Эффективность: " << new_cs.efficiency << "\n\n";
}

void EditTube(tube& new_tube)
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

void EditStation(cs& new_cs)
{
	cout << "------------ Редактирование КС ------------\n";
	cout << "Количество работающих цехов на данный момент: " << new_cs.active_rooms << endl;
	cout << "<0> - Убрать активный цех, <1> - Добавить активный цех\n";
	switch (CorrectChoice())
	{
	case 1:
		if (IsPosibleTransformation(new_cs) == true)
		{
			new_cs.active_rooms++;
			cout << "Кол-во работающих цехов: " << new_cs.active_rooms << endl;
		}
		break;
	case 0:
		if (IsPosibleTransformation(new_cs) == true)
		{
			new_cs.active_rooms--;
			cout << "Кол-во работающих цехов: " << new_cs.active_rooms << endl;
		}
		break;
	default:
		break;
	}
}

void Save(tube& new_tube, cs& new_cs)
{
	//CreatedCheck(new_tube, new_cs);
	ofstream out("Tubes.txt");
	if (out.is_open())
	{
		out << "#####################" << endl;
		out << "Длина: " << new_tube.length << endl;
		out << "Диаметр: " << new_tube.diameter << endl;
		out << "Состояние: " << new_tube.condition << endl;
		out << "#####################" << endl;
		out << "Всего цехов: " << new_cs.rooms << endl;
		out << "Цехов в работе: " << new_cs.active_rooms << endl;
		out << "Эффективность: " << new_cs.efficiency << endl;
	}
	out.close();
	cout << "Данные по трубе сохранены\n\n";
	cout << "Данные по КС сохранены\n\n";
}

//void Download2(tube& new_tube, cs& new_cs)
//{
//	new_tube = {};
//	ifstream in("Tubes.txt");
//	if (in.is_open())
//	{		
//		while (in >> new_tube.length)
//		{
//			if (in.fail() || in.peek() != '\n')
//			{
//				in.clear();
//				in.ignore(1000, '\n');
//				cout << new_tube.length;
//			}
//			cout << new_tube.length;
//		}		
//	}
//	in.close();
//}

void Download(tube& new_tube, cs& new_cs)
{
	int error_flag = 0;
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
				CommaSubstitution(line);
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
				CommaSubstitution(line);
				if (IsDoubleNumber(line) and stod(line) > 0)
				{
					new_tube.diameter = stod(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "Состояние:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				if (IsNumber(line) and stoi(line) > 0 and stoi(line) <= 5)
				{
					new_tube.condition = stoi(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "цехов:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end()); //https://ru.stackoverflow.com/questions/1071460/%D0%A3%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D1%80%D0%BE%D0%B1%D0%B5%D0%BB%D0%BE%D0%B2-%D0%B8%D0%B7-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8
				if (IsNumber(line) and stoi(line) > 0)
				{
					new_cs.rooms = stoi(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "работе:")
			{
				getline(in, line);
				line.erase(remove(line.begin(), line.end(), ' '), line.end());
				if (IsNumber(line) and stoi(line)<= new_cs.rooms)
				{
					new_cs.active_rooms = stoi(line);
				}
				else
				{
					error_flag = 1;
				}
			}
			if (current_word == "Эффективность:")
			{
				getline(in, line);
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
	in.close();
	InfoMessage(new_tube, new_cs, error_flag);
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
	do { ShowMenu(); } while (Menu(new_tube, new_cs) != 0);
}