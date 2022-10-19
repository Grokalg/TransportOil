#include "CCs.h"
#include "utils.h"
#include <iostream>

void CreateStation(cs& new_cs)
{
	cout << "������� ��������: ";
	getline(cin >> ws, new_cs.name);
	cout << "������� ���������� �����: ";
	new_cs.rooms = InputRooms();
	cout << "������� ���������� ���������� �����: ";
	new_cs.active_rooms = InputActiveRooms(new_cs);
	cout << "������� �������� ������������� (�� 1 �� 5): ";
	new_cs.efficiency = InputEfficiency();
}

void EditStation(cs& new_cs)
{
	if (new_cs.rooms == 0)
	{
		cout << "�� ��� �� �������\n";
	}
	else
	{
		cout << "------------ �������������� �� ------------\n";
		cout << "���������� ���������� ����� �� ������ ������: " << new_cs.active_rooms << endl;
		cout << "<0> - ������ �������� ���, <1> - �������� �������� ���\n";
		switch (CorrectChoice())
		{
		case 1:
			if (IsPosibleTransformationAdd(new_cs))
			{
				new_cs.active_rooms++;
				cout << "���-�� ���������� �����: " << new_cs.active_rooms << endl;
			}
			break;
		case 0:
			if (IsPosibleTransformationSub(new_cs))
			{
				new_cs.active_rooms--;
				cout << "���-�� ���������� �����: " << new_cs.active_rooms << endl;
			}
			break;
		default:
			break;
		}
	}
}