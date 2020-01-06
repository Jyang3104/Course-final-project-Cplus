
#ifndef SDDS_PUBREC_H
#define SDDS_PUBREC_H
#include <iostream>
#include "ReadWriteable.h"
#include "Date.h"
namespace sdds
{
	const int SDDS_CONSOLE=10;
	const int SDDS_FILE = 9;
	
	class PubRecord :public ReadWriteable {
		
		char* recName=nullptr;
		int shelfNum;
		int type;
	protected:
		void name(const char* na);
		const char* name() const;

		void shelfNo(int value);
	public:
		virtual char recID() const=0;
		virtual void checkIn() = 0;
		virtual void checkOut() = 0;

		PubRecord();
		PubRecord(const PubRecord& src);

		virtual~PubRecord();
		PubRecord& operator=(const PubRecord& src);
		void mediaType(const int ty);
		int mediaType() const;
		const int shelfNo() const;
		std::istream& readShelfNo(std::istream& is=std::cin);
		const char* getName() const;
		bool operator==(const char id)const;
		bool operator==(const char* sub)const;
		bool operator!() const;
		operator bool()const;
	};
}
#endif

