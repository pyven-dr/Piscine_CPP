#include <string>
#include "Array.hpp"

int main(void)
{
	Array<std::string> array(3);

	array[0] = "test1";
	array[1] = "test2";
	array[2] = "test3";
	array.printArray();
	std::cout << array.size() << std::endl;

	Array<std::string> array2 = array;
	array2.printArray();
	try
	{
		array[2];
	}
	catch (std::exception& e)
	{
		std::cout << "Out of range" << std::endl;
	}

	try
	{
		array[3];
	}
	catch (std::exception& e)
	{
		std::cout << "Out of range" << std::endl;
	}
	return (0);
}