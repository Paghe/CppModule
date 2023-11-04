#include "Serialazer.hpp"


int	main(void)
{
	Data DataSerializer;

	DataSerializer.value = 42;
	uintptr_t ptr = Serializer::serialize(&DataSerializer);
	Data *DataCopy = Serializer::deserialize(ptr);
	uintptr_t ptrCopy = Serializer::serialize(DataCopy);
	std::cout << "Numeric address rep ---> " << ptr << std::endl;
	std::cout << "Numeric address rep cpy ---> " << ptrCopy << std::endl;
	std::cout << "Address struct ---> " << &DataSerializer << std::endl;
	std::cout << "Address struct cpy ---> " << DataCopy << std::endl;
	std::cout << "Original value ---> " << DataSerializer.value << std::endl;
	std::cout << "Value cpy ---> " << DataCopy->value << std::endl;
	return (0);
}