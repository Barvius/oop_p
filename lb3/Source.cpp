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
	
	//Literature **_Literature = NULL;
	//_Literature = new Literature *[10];
	//int p = 0;
	

	Rack *_Racks = NULL;
	_Racks = new Rack[5];
	_Racks[0] = Rack(5,1);

	for (int i = 0; i <7; i++) {
		//_Racks[0].AddLiterature(Book(idBook[i], NameBook[i], AuthorBook[i], PublishingHouseBook[i]));
		//Book k(Book(idBook[i], NameBook[i], AuthorBook[i], PublishingHouseBook[i]));
		//_Literature[p++] = new Book(k);

		librarian.AddLiteratureInRack(Book(idBook[i], NameBook[i], AuthorBook[i], PublishingHouseBook[i]));
		librarian.GetAllLiteratureInRacks();
	}
	for (int i = 0; i < 3; i++) {
		//_Literature[p++] = new Journal(idJournal[i], NameJournal[i], SubjectsJournal[i], PeriodicityJournal[i]);
		librarian.AddLiteratureInRack(Journal(idJournal[i], NameJournal[i], SubjectsJournal[i], PeriodicityJournal[i]));
	}

	
	while (true) {
		//system("cls");
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