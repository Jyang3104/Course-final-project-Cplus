#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Menu.h"
#include <cstring>
using namespace std;
namespace sdds
{

	//member functions of MENUITEM
	Menuitem::Menuitem() {
		description = nullptr;
	}
	Menuitem::Menuitem(const char* name) {
		setItem(name);
	}
	Menuitem::~Menuitem() {

		//cout << "destructor: " << description << endl;
		delete[] description;
	}
	Menuitem::operator bool() const {
		bool noEmp = true;
		if (description == nullptr) {
			noEmp = false;
		}
		return noEmp;
	}
	Menuitem::operator char* () const {
		return description;
	}
	ostream& Menuitem::display(ostream& os) const {
		//os << "in dispaly menuitem";
		if (description != nullptr) {
			os << description;
		}
		return os;
	}

	void Menuitem::setItem(const char* name) {
		//cout << "set the value of Menuitem"<<endl;
		int len = strlen(name);
		description = new char[len + 1];
		strncpy(description, name, len);
		description[len] = '\0';
	}

	//member functions of MENU
	Menu::Menu() {
		noOfItem = 0;
	}
	Menu::Menu(const char* name) {
		title.setItem(name);
		noOfItem = 0;
	}
	Menu::~Menu() {
		//cout << "Menu destructor" << endl;
		for (int i = 0; i < noOfItem; i++) {
			
			delete menuItems[i];
		}
	}
	void Menu::display() const {
		if (title != nullptr) {
			cout << title.description << ':' << endl;
		}

		for (int i = 0; i < noOfItem; i++) {
			cout << setfill(' ') << setw(2)<<right << i + 1 << "- ";
			menuItems[i]->display(cout);
			cout << endl;
		}
		cout << " 0- Exit\n" << "> ";

	}
	ostream& Menu::displayTitle(ostream& os)const {
		//os << "in display title";
		title.display(os);
		return os;
	}

	unsigned int Menu::getSelection()const {
		int choice = -1;
		bool ok=false;
        display();
		while (!ok) {
			
			cin >> choice;
			if (cin.fail()||cin.get() != '\n') {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: " ;
			}
			else {
				if (choice > noOfItem || choice < 0) {
				cout << "Invalid Selection, try again: ";
				}
				else {
					ok = true;
				}
			}
			
		}
		return choice;

	}
	void Menu::addItem(const char* item) {
		//cout << "in add function"<<endl;
		menuItems[noOfItem] = new Menuitem(item);
		noOfItem++;
	}
	unsigned int Menu::operator~() const {
		return this->getSelection();
	}
	Menu::operator unsigned int() const {
		return noOfItem;
	}
	Menu::operator bool() const {
		return (noOfItem > 0);
	}
	char* Menu::operator[](int index)const {
		return menuItems[index]->description;
	}

	//helper functions
	ostream& operator<<(ostream& os, const Menu& menu) {
		//os << "in overload operator Menu";
		menu.displayTitle(os);
		return os;
	}
	Menu& operator<<(Menu& menu, const char* item) {
		//cout << "add item" << endl;
		menu.addItem(item);
		
		return menu;
	}

}