
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "PubRecord.h"
#include "Date.h"
namespace sdds
{
	class Book :public PubRecord {
		long long ISBN;
		int memID;
		Date due;
	public:
		Book();
		Book(const Book& src);

		virtual char recID() const;
		virtual void checkIn();
		virtual void checkOut();
		virtual std::istream& read(std::istream& is = std::cin);
		virtual std::ostream& write(std::ostream& os = std::cout) const;
		int memberID()const;
		long long getISBN() const;
		Book& operator=(const Book& src);
	};
}
#endif
