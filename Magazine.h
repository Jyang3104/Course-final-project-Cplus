#ifndef SDDS_MAGZ_H
#define SDDS_MAGZ_H
#include <iostream>
#include "PubRecord.h"

namespace sdds
{
	class Magazine : public PubRecord {
	
		int volume;
		int issueNo;
	public:
		Magazine();
		Magazine(const Magazine& src);

		virtual char recID() const;
		virtual void checkIn();
		virtual void checkOut();
		virtual std::istream& read(std::istream& is = std::cin);
		virtual std::ostream& write(std::ostream& os = std::cout) const;
		int getVol() const;
		int getIssu() const;
	
	};
	


}
#endif
