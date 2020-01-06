
#ifndef SDDS_READWRITE_H
#define SDDS_READWRITE_H
#include <iostream>

namespace sdds
{
	class ReadWriteable {
	public:
		virtual std::istream& read(std::istream& is = std::cin)=0;
		virtual std::ostream& write(std::ostream& os = std::cout) const =0;
	};

	std::ostream& operator<<(std::ostream& os, const ReadWriteable& rw);
	std::istream& operator>>(std::istream& is, ReadWriteable& rw);
}
#endif