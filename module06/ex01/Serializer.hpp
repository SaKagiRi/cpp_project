#pragma once

// #include <cstdint>
#include <stdint.h>
#include <iostream>

typedef struct s_data
{
	std::string content;
} Data;

class Serializer
{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer& source);
		Serializer& operator=(const Serializer& source);
	public:
		static uintptr_t serializer(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};
