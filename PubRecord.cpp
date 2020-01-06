

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "PubRecord.h"
namespace sdds
{
	void PubRecord::name(const char* na) {
		int len = strlen(na);

		if (recName != nullptr) {
			delete[] recName;
		}
		recName = new char[len + 1];
		strncpy(recName, na, len);
		recName[len] = '\0';
	}
	const char* PubRecord::name() const {
		return recName;
	}

	PubRecord::PubRecord() {
		type = SDDS_CONSOLE;
		shelfNum = 0;
		name("NO");
	
	}
	PubRecord::PubRecord(const PubRecord& src) {
		*this = src;
		
	}
	PubRecord::~PubRecord() {
		//cout << "destructor" << endl;
		delete[] recName;
	}
	PubRecord& PubRecord::operator=(const PubRecord& src) {
		if (this != &src) {
			//shallow copy
			type = src.mediaType();
			shelfNum = src.shelfNo();

			//deep copy
			name(src.getName());
		}
		return *this;
	
	}
	const char* PubRecord::getName() const {
		return recName;
	}
	void PubRecord::mediaType(const int ty) {
		if (ty == SDDS_CONSOLE || ty == SDDS_FILE) {
			type = ty;
		}
		else {
			type = 0;
		}
	}
	int PubRecord::mediaType() const {
		return type;
	}
	const int PubRecord::shelfNo() const {
		return shelfNum;
	}
	istream& PubRecord::readShelfNo(istream& is) {
		bool ok = false;
		
		while (!ok) {
			is >> shelfNum;
			if (is.fail() || is.get() != '\n') {
				is.clear();
			    is.ignore(1000, '\n');
				cout << "Invalid Shelf Number, Enter again: ";
			}
			else {
				if (shelfNum > 999 || shelfNum < 100) {
					cout << "Invalid Shelf Number, Enter again: ";
				}
				else {
					ok = true;
				}
			}
		
		}
		return is;
	}
	bool PubRecord::operator==(const char id) const{
		bool equal = false;
		if (id == recID()) {
			equal = true;
		}
		return equal;
	}
	bool PubRecord::operator==(const char* sub) const{
		char* subst = strstr(recName, sub);
		bool substring = false;
		if (subst != nullptr) {
			substring = true;
			//delete[] subst;
		}
		return substring;
	}
	bool PubRecord::operator!() const {
		bool emp = false;
		if (type == SDDS_CONSOLE && shelfNum == 0&&(strcmp(recName,"NO")==0)) {
			emp = true;
		}
		return emp;
	}
	void PubRecord::shelfNo(int value) {
		shelfNum = value;
	}

	PubRecord::operator bool()const {
		return (shelfNum != 0);
	}
}