#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t raw_data;
	Data *data_deserialize;

	data.a = 42;
	data.b = 123456789;
	std::cout << "Base struct : " << data.a << " " << data.b << std::endl;
	raw_data = Serializer::serialize(&data);
	data_deserialize = Serializer::deserialize(raw_data);
	std::cout << "Deserialized : " << data_deserialize->a << " " \
		<< data_deserialize->b << std::endl;
}
