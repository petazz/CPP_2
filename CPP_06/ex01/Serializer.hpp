#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
public:
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

	static uintptr_t serialize(void *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif