#include "CTube.h"
#include "utils.h"
#include <iostream>

using namespace std;

void CreateTube(tube& new_tube)
{
	cout << "������� ����� � ������ (����������� <.>): ";
	new_tube.length = UserInputParameter();
	cout << "������� ������� � ������ (����������� <.>): ";
	new_tube.diameter = UserInputParameter();
	cout << "����� ��������\n\n";
	new_tube.condition = 1;
}

void EditTube(tube& new_tube)
{
	if (new_tube.length == 0)
	{
		cout << "����� ��� �� �������\n";
	}
	else
	{
		cout << "------------ �������������� ����� ------------\n";
		cout << "������� �������� ���������:\n";
		cout << "<1> - ����� ��������  <0> - ����� � �������\n";
		switch (CorrectChoice())
		{
		case 1:
			new_tube.condition = 1;
			break;
		case 0:
			new_tube.condition = 0;
			break;
		default:
			cout << "��������� ������ �� ���������.\n";
			break;
		}
	}
}