#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds
{
	class Menuitem {
		char* description=nullptr;

		friend class Menu;
		Menuitem();
		Menuitem(const char*);
		~Menuitem();
		operator bool() const;
		operator char* () const;
		std::ostream& display(std::ostream& os = std::cout) const;
		void setItem(const char*);
	};
	class Menu {
		static const int MAX_MENU_ITEMS = 20;
		Menuitem title;
		Menuitem* menuItems[MAX_MENU_ITEMS];
		int noOfItem;
		void addItem(const char*);
	public:
		Menu();
		Menu(const char*);
		~Menu();
		void display() const;

		unsigned int getSelection()const;
		std::ostream& displayTitle(std::ostream& os)const;
		unsigned int operator~()const;
		operator unsigned int()const;
		operator bool()const;
		char* operator[](int index)const;
		
		friend Menu& operator<<(Menu& menu, const char* item);


	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
	Menu& operator<<(Menu& menu, const char* item);

}
#endif
