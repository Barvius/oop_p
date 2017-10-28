#include "Rack.h"

using namespace std;

bool Rack::AddLiterature(Journal& obj) {
	if (_CountBooks == _Size) {
		return false;
	} else {
		_Literature[_CountBooks] = new Journal(obj);
		_CountBooks++;
		return true;
	}
}

bool Rack::AddLiterature(Book& obj) {
	if (_CountBooks == _Size) {
		return false;
	} else {
		_Literature[_CountBooks] = new Book(obj);
		_CountBooks++;
		return true;
	}
}

void Rack::GetAllLiteratureInRack() {
	cout << "На полке " << _NumberRack << " (" << _CountBooks << " из " << _Size << ")" << endl;
	for (size_t i = 1; i < _CountBooks; i++) {
		_Literature[i]->Info();
		cout << endl;
	}

}

int Rack::GetNumberRack() {
	return _NumberRack;
}

void Rack::GetBookByName(char* str) {
	for (size_t i = 0; i < _CountBooks; i++) {
		if (!strcmp(_Literature[i]->GetName(), str)) {
			cout << "Книга на полке " << _NumberRack << endl;
			_Literature[i]->Info();
		}
	}
}

Rack::Rack() {

}

Rack::Rack(Rack &obj) {

}

Rack::Rack(int n, int number) {
	_Size = n;
	_NumberRack = number;
	_Literature = new Literature *[n];
}

Rack::~Rack() {
	for (int i = 0; i < _Size-1; i++) {
//		delete[] _Literature[i];
	}
	delete[] _Literature;
}
