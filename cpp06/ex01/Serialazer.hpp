#pragma once
#include <cstdint>
#include <iostream>

struct Data
{
	int value;
};

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer & preset);
	Serializer& operator=(Serializer const & cpy);
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};