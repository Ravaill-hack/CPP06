
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.h"

class Serializer
{
	public:
		~Serializer();
		static uintptr_t serialize(t_Data* ptr);
		static t_Data *deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer & toCopy);
		Serializer & operator=(const Serializer & other);
};

#endif
