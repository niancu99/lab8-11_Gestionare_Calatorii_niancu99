#include "UI.h"
#include "ValException.h"
#include "RepoException.h"

UI::UI()
{
}

UI::UI(Service& serv)
{
}

UI::~UI()
{
}

void UI::menu() {
	cout << endl;
	cout << "Optiuni: " << endl;
	cout << endl;
	cout << "1. Add bus" << endl;
	cout << "2. Add plane" << endl;
	cout << "3. Search travel by date" << endl;

	cout << "5. Logout" << endl;
	cout << "0. Exit" << endl;
}

void UI::UIAddBus()
{
	cout << "Cod: "; 
	string code; cin >> code;
	cout << "Locul plecarii: "; 
	string plecare; cin >> plecare;
	cout << "Locul destinatie: ";
	string destinatie; cin >> destinatie;
	cout << "Data: ";
	string data; cin >> data;
	int nr_totale;
	cout << "Numar locuri totale: "; cin >> nr_totale;
	int nr_rezervate;
	cout << "Numar locuri rezervate: "; cin >> nr_rezervate;
	int nr_zile;
	cout << "Numar zile: "; cin >> nr_zile;
	try {
		this->serv.addBus(code, plecare, destinatie, data, nr_totale, nr_rezervate, nr_zile);
	}
	catch (ValException & e) {
		cout << e.what() << endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::UIAddAvion()
{
	string code; cin >> code;
	cout << "Locul plecarii: ";
	string plecare; cin >> plecare;
	cout << "Locul destinatie: ";
	string destinatie; cin >> destinatie;
	cout << "Data: ";
	string data; cin >> data;
	int nr_totale;
	cout << "Numar locuri totale: "; cin >> nr_totale;
	int nr_rezervate;
	cout << "Numar locuri rezervate: "; cin >> nr_rezervate;
	bool escale;
	cout << "Escala(true/false): "; cin >> escale;
	try {
		serv.addAvion(code, plecare, destinatie, data, nr_totale, nr_rezervate, escale);
	}
	catch (ValException & e) {
		cout << e.what() << endl;
	}
	catch (RepoException & e) {
		cout << e.what() << endl;
	}
}

void UI::SearchByDate()
{
	cout << "Data pentru cautare: "; 
	string date;
	cin >> date;
	for (Calatorie* c : this->serv.searchbyDate(date))
		cout << c->toString(" ") << endl;
}

void UI::chooseFormatFile()
{
	int option = 0;
	cout << "1. TXT / 2. CSV: "; cin >> option;
	while (option < 1 or option > 2) {
		cout << "Incearca din nou: "; cin >> option;
	}
	if (option == 1)
		this->serv.set_repo(new RepoTXT("Calatorii.txt"));
	else
		this->serv.set_repo(new RepoCSV("Calatorii.csv"));
}

void UI::run()
{
	int opt;
	bool go = true;
	cout << "	LOGIN	" << endl;
	cout << "Username: "; string user; cin >> user;
	cout << "Password: "; string password; cin >> password;
	this->serv.loadFromFile();
	if (this->serv.logare(user, password));
	{
		cout << endl;
		this->chooseFormatFile();
		for (Calatorie* c : this->serv.getAllCalatorii())
			cout << c->toString(" ") << endl;
		while (go) {
			this->menu();
			cout << "Optiune:"; cin >> opt;
			switch (opt) {
			case 1: {UIAddBus(); break; }
			case 2: {UIAddAvion(); break; }
			case 3: {SearchByDate(); break; }
			case 5: {cout << "Logged out" << endl; go = false; }
			case 0: {go = false; break; }
			}
		}
	}
	cout << endl;
	cout << "Login? 1. Da 2. Nu"; 
	int option; cin >> option;
	switch (option) {
	case 1: {run(); }
	case 2: {break; }
	}
}
