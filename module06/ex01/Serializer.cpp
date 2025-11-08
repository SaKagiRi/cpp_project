#include "Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::~Serializer(void) {}
Serializer::Serializer(const Serializer &source) { (void)source; }
Serializer &Serializer::operator=(const Serializer &source) {
  (void)source;
  return (*this);
}
uintptr_t Serializer::serializer(Data *ptr){
	std::cout << ptr << " : " << reinterpret_cast<uintptr_t>(ptr) << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << raw << " : " << reinterpret_cast<Data *>(raw) << std::endl;
	return (reinterpret_cast<Data*>(raw));
}
