#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTube()
{
	double length, diameter;
	string id;
	cout << "Введите номер трубы: ";
	cin >> id;
	string current_word;
	ifstream in("Tubes.txt");
	if (in.is_open())
	{
		while (in >> current_word)
		{
			if (current_word == id)
			{
				cout << "Труба с таким номером уже существует. Пожалуйста выберете другой.\n";
				cout << "Введите номер трубы: ";
				cin >> id;
			}
		}
	}
	in.close();
	cout << "Введите длину: ";
	cin >> length;
	cout << "Введите диаметр: ";
	cin >> diameter;
	cout << "Труба исправна\n\n";
	ofstream out("Tubes.txt", ios::app);
	if (out.is_open())
	{
		out << "#####################" << endl;
		out << "Труба номер: " << id << endl;
		out << "Длина: " << length << endl;
		out << "Диаметр: " << diameter << endl;
		out << "Труба исправна" << endl;
	}
	out.close();
}

void CreateStation()
{
	string name, number_of_workshops, number_of_active_workshops, efficiency;
	cout << "Придумайте название: ";
	cin >> name;
	cout << "Укажите количество цехов: ";
	cin >> number_of_workshops;
	cout << "Укажите количество работающих цехов: ";
	cin >> number_of_active_workshops;
	cout << "Введите значение эффективности: ";
	cin >> efficiency;
}

void ViewAllObjects()
{
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
}

void EditTube()
{
	int id;
	cout << "Выберете и напишите номер трубы, данные которой вы хотите радактировать.\n";
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
					cout << line << endl;
				}
			}
		}
	}
	in.close();
	cin >> id;
}

void Menu()
{
	int x;
	setlocale(0, "");
	cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
	cin >> x;
	switch (x) 
	{
		case 1:
			system("cls");
			CreateTube();
			break;
		case 2:
			system("cls");
			CreateStation();
			break;
		case 3:
			system("cls");
			ViewAllObjects();
			break;
		case 4:
			system("cls");
			EditTube();
			break;
		default:
			cout << "Введенные данные не корректны. Пожалуйста, укажите номер, интересующего вас пункта.\n";
	}
	Menu();
}

int main()
{
	Menu();
}