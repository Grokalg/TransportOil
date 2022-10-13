#include <iostream>
#include <fstream>
#include <string>
//#include <cctype>   // для функции isdigit

using namespace std;

struct tube
{
	double length = 0;
	double diameter = 0;
	int condition = 0;
};

struct cs
{
	string name;
	int rooms = 0;
	int active_rooms = 0;
	int efficiency = 0;
};

double UserInputParameter()
{
	double parameter;
	cin >> parameter;
	while (cin.fail() || cin.peek() != '\n' || parameter <= 0)
	{
		cout << "Введенные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> parameter;
	}
	return parameter;
}

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

string InputName()
{
	string name;
	cin >> name;
	while (cin.fail() || cin.peek() != '\n')
	{
		cout << "Введенные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> name;
	}
	return name;
}

int InputActiveRooms(cs& new_cs)
{
	int active_rooms;
	cin >> active_rooms;
	while (cin.fail() || cin.peek() != '\n' || active_rooms > new_cs.rooms || active_rooms < 0)
	{
		cout << "Введенные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> active_rooms;
	}
	return active_rooms;
}

int InputEfficiency()
{
	int efficiency;
	cin >> efficiency;
	while (cin.fail() || cin.peek() != '\n' || efficiency <= 0 || efficiency > 5)
	{
		cout << "Введенные данные не корректны\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> efficiency;
	}
	return efficiency;
}

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

void CreateTube(tube& new_tube)
{
	cout << "Введите длину в метрах (используйте <.>): ";
	new_tube.length = UserInputParameter();
	cout << "Введите диаметр в метрах (используйте <.>): ";
	new_tube.diameter = UserInputParameter();
	cout << "Труба исправна\n\n";
	new_tube.condition = 1;
}

void CreateStation(cs& new_cs)
{
	cout << "Введите название: ";
	getline(cin>>ws, new_cs.name);
	cout << "Укажите количество цехов: ";
	new_cs.rooms = InputRooms();
	cout << "Укажите количество работающих цехов: ";
	new_cs.active_rooms = InputActiveRooms(new_cs);
	cout << "Введите значение эффективности (от 1 до 5): ";
	new_cs.efficiency = InputEfficiency();
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
		while (in >> current_word)
		{
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
	do { ShowMenu(); } while (Menu(new_tube, new_cs) != 0);
}