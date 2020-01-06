
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "Magazine.h"
namespace sdds
{
	Magazine::Magazine() :PubRecord() {
	
		volume = 0;
		issueNo = 0;
}
	Magazine::Magazine(const Magazine& src): PubRecord(src) {
		volume = src.getVol();
		issueNo = src.getIssu();
	
	}

	int Magazine::getVol() const {
		return volume;
	}
	int Magazine::getIssu() const {
		return issueNo;
	}
	char Magazine::recID() const {
		return 'M';
	}
	void Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	void Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	istream& Magazine::read(istream& is) {
		if (mediaType() == SDDS_CONSOLE) {
			//Read magazine name
			cout << "Magazine Name: ";
			char tempName[41];
			bool nameOk = false;
			while (!nameOk) {
				
				is.getline(tempName,40,'\n');
				if (is.fail()) {
					
					is.clear();
					is.ignore(1000, '\n');
					cout << "Magazine name too long, Enter again: ";
				}
				else {
				
					name(tempName);
					nameOk = true;
				}
			
			}

		
         //read magazine volumn
			cout << "Volume: ";
			bool VolOk = false;

			while (!VolOk) {
				is >> volume;
				if (is.fail() || is.get() != '\n') {
					is.clear();
					is.ignore(1000, '\n');
					cout << "Invalid Volume number, Enter again: ";
				}
				else {
					if (volume >99 || volume < 1) {
						cout << "Invalid Volume number, Enter again: ";
					}
					else {
						VolOk = true;
					}
				}

			}


			//read issue Number
			cout << "Issue: ";
			bool IssOk = false;

			while (!IssOk) {
				is >> issueNo;
				if (is.fail() || is.get() != '\n') {
					is.clear();
					is.ignore(1000, '\n');
					cout << "Invalid Issue number, Enter again: ";
				}
				else {
					if (issueNo > 99 || issueNo < 1) {
						cout << "Invalid Issue number, Enter again: ";
					}
					else {
						IssOk = true;
					}
				}

			}


			//read shelfNo
			cout << "Shelf Number: ";
			readShelfNo(is);
		}
		else if (mediaType() == SDDS_FILE) {
			char tN[41];
			int tV;
			int tI;
			int tS;
			is.getline(tN, 40, '\t');
			is >> tV >> tI >> tS;
			is.get();
			if (is.fail()) {
				cout << "Invalid input"<<endl;
			}
			else {
				if (tV < 1 || tV>99) {
					cout << "invalid Volume" << endl;
				}
				else if (tI < 1 || tI>99) {
					cout << "invalid Issue" << endl;
				}
				else if (tS < 100 || tS>999) {
					cout << "invalid Shelf" << endl;
				}
				else {
					volume = tV;
					issueNo = tI;
					shelfNo(tS);
					name(tN);
				}
			}
		
		}

			return is;
	}
	ostream& Magazine::write(ostream& os) const {
		if (mediaType() == SDDS_CONSOLE) {
			os << setw(41) << left<<setfill(' ') << name();
			os << "       ";
			os << setw(2) << right << setfill('0') << volume << '(';
			os << setw(2) << right << setfill('0') << issueNo << ")  ";
			os << shelfNo()<< setfill(' ');

		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() << name()<<'\t';
			os << volume << '\t' << issueNo << '\t';
			os << shelfNo() << endl;
		}
	
		return os;
	}
}