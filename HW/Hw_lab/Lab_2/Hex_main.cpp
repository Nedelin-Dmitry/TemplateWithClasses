#include <iostream>
#include"hex_class.h"

int main()
{
	Hex A = Hex("A1");
	Hex B = Hex("B1");
	Hex Result1 = Hex();
	
	Result1 = A + B;
	for (int i = 0; i < Result1.get_size(); i++)
	{
		int output_int = Result1.get_int_i(i);
		std::cout << output_int << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < Result1.get_size(); i++)
	{
		char output_char = Result1.get_char_i(i);
		std::cout << output_char << " ";
	}
	std::cout << std::endl;