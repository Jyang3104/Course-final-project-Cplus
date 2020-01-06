
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "Book.h"
namespace sdds
{
	Book::Book():PubRecord() {
		ISBN=0;
		memID=0;
		
	}
	Book::Book(const Book& src): PubRecord(src),due(src.due) {
		ISBN = src.getISBN();
		memID = 0;

	}
	long long Book::getISBN() const {
		return ISBN;
	}
	
	char Book::recID() const {
		return 'B';
	}
	void Book::checkIn() {
		memID = 0;
		write();
		cout << " checked in!" << endl;
	}
	void Book::checkOut() {
		
		//get 5 digits and set the memberID
		bool IDOk = false;
            cout << "Enter Member id: ";
		while (!IDOk) {
			
			cin >> memID;
			if (cin.fail() || cin.get() != '\n') {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Member ID, Enter again: ";
			}
			else {
				if (memID > 99999 || memID < 10000) {
					cout << "Invalid Member ID, Enter again: ";
				}
				else {
					IDOk = true;
				}
			}
		}


		//get the return date
		
		
		Date currDate;
		do {
			if ((due - currDate) < 0) {
				cout << "Please enter a future date."<<endl;
			}
			else if ((due - currDate) > 30) {
				cout << "The return date must be earlier than 30 days away from today.";
			}

			do {
				cout << "Enter return date: ";
				cin >> due;
			} while (!due && (cout << due.dateStatus() << ','));
		} while ((due - currDate)>30|| (due - currDate)<0);

		
	}
	istream& Book::read(istream& is) {
	if (mediaType() == SDDS_CONSOLE) {
			//Read Book name
			cout << "Book Name: ";
			char tempName[41];
			bool nameOk = false;
			while (!nameOk) {
				
				is.getline(tempName,40,'\n');
				if (is.fail()) {
					
					is.clear();
					is.ignore(1000, '\n');
					cout << "Book name too long, Enter again: ";
				}
				else {
				
					name(tempName);
					nameOk = true;
				}
			
			}

		
         //read book ISBN
			cout << "ISBN: ";
			bool ISBNOk = false;

			while (!ISBNOk) {
				is >> ISBN;
				if (is.fail() || is.get() != '\n') {
					is.clear();
					is.ignore(1000, '\n');
					cout << "Invalid ISBN, Enter again: ";
				}
				else {
					if (ISBN >9999999999999 || ISBN < 1000000000000) {
						cout << "Invalid ISBN, Enter again: ";
					}
					else {
						ISBNOk = true;
					}
				}

			}
			//read shelfNo
			cout << "Shelf Number: ";
			readShelfNo(is);
		}
		else if (mediaType() == SDDS_FILE) {
			char tN[41];
			long long tIS;
			int tMem;
			int tS;
			is.getline(tN, 41, '\t');
			is >> tIS >> tS >> tMem;
			//is.get();
			if (is.fail()) {
				cout << "Invalid input"<<endl;
			}
			else {
				if (tIS < 1000000000000 || tIS>9999999999999) {
					cout << "invalid ISBN" << endl;
				}
				else if (tS < 100 || tS>999) {
					cout << "invalid Shelf" << endl;
				}
				else {
					ISBN = tIS;
					memID = tMem;
					shelfNo(tS);
					name(tN);
				}
				if (tMem > 0) {
					is >> due;
					
				}
			}
		}

			return is;
	}
	ostream& Book::write(ostream& os) const {
		if (mediaType() == SDDS_CONSOLE) {
			os << setw(41) << left<<setfill(' ') << name();
			os << ISBN<<"  "<<shelfNo()<< setfill(' ');
			if (memID > 0) {
				os << ' ' << memID << "   " << due << setfill(' ');
			}

		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name() << '\t';
			os << ISBN << '\t' << shelfNo() << '\t';
			os << memID;
			if (memID > 0) {
				os << '\t' << due;
			
			}
			os << endl;
		}

		return os;
	
	}
	int Book::memberID()const {
		return memID;
	}
	Book& Book::operator=(const Book& src){
		if (this != &src) {
			//shallow copy
			mediaType( src.mediaType());
			shelfNo(src.shelfNo());
			ISBN = src.getISBN();
			memID = 0;
			//deep copy
			name(src.getName());
		}
		return *this;
	
	}
}