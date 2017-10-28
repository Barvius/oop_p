#include <iostream>
#include <windows.h>
#include <typeinfo>
#include "Rack.h"
#include "Book.h"
#include "Journal.h"
#include "Librarian.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 6;
	int idBook[] = { 107,323,122,558,696,666,132 };
	char *NameBook[] = { "������ � �������� ���","�������� � ������� ���� ������","������� ���","���������","�����������. ��� �����","����� �����","����� ���� �������" };
	char *AuthorBook[] = { "��� ������","��� �������","������ ��������","���� ����������","����� ��������","���� ��������","��� �������" };
	char *PublishingHouseBook[] = { "���","���","���","���","�����","�����","���" };
	int idJournal[] = { 241, 412, 532 };
	char *NameJournal[] = { "Linux Format", "���� ������", "�����" };
	char *SubjectsJournal[] = { "IT", "�������", "IT" };
	char *PeriodicityJournal[] = { "����������", "����������", "����������" };

	Librarian librarian;
	librarian.CreateBookshelf(N);

	for (int i = 0; i <7; i++) {
		librarian.AddLiteratureInRack(Book(idBook[i], NameBook[i], AuthorBook[i], PublishingHouseBook[i]));
	}
	for (int i = 0; i < 3; i++) {
		librarian.AddLiteratureInRack(Journal(idJournal[i], NameJournal[i], SubjectsJournal[i], PeriodicityJournal[i]));
	}

	
	while (true) {
		system("cls");
		cout << "1 - �������� ����� �� ���� ������" << endl;
		cout << "2 - ����� �� ������ �����" << endl;
		switch (cin.get()) {
		case '1':
			system("cls");
			librarian.GetAllLiteratureInRacks();
			system("pause");
			break;
		case '2':
			system("cls");
			cout << "������� ��������:";
			cin.ignore();
			char tmp[100];
			cin.getline(tmp, 100);
			librarian.GetBookByName(tmp);
			system("pause");
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}