#include "Serialazer.hpp"


int	main(void)
{
	Data DataSerialezer;

	DataSerialezer.value = 42;
	uintptr_t ptr = Serializer::serialize(&DataSerialezer);
	Data *DataCopy = Serializer::deserialize(ptr);
	uintptr_t ptrCopy = Serializer::serialize(DataCopy);
	std::cout << "Numeric address rep ---> " << ptr << std::endl;
	std::cout << "Numeric address rep cpy ---> " << ptrCopy << std::endl;
	std::cout << "Address struct ---> " << &DataSerialezer << std::endl;
	std::cout << "Address struct cpy ---> " << DataCopy << std::endl;
	std::cout << "Original value ---> " << DataSerialezer.value << std::endl;
	std::cout << "Value cpy ---> " << DataCopy->value << std::endl;
	return (0);
}