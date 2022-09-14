#include <iostream>

using namespace std;

void CreateTube()
{
	double length, diameter;
	cout << "Введите длину: ";
	cin >> length;
	cout << "Введите диаметр: ";
	cin >> diameter;
	cout << "Труба исправна\n\n";
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
		default:
			cout << "Введенные данные не корректны. Пожалуйста укажите номер, интересующего вас пункта.\n";
	}
	Menu();
}

int main()
{
	Menu();
}