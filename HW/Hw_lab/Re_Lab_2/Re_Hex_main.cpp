#include <iostream>
#include"Re_Hexr.h"

int main()
{
	Hex A = Hex("FE1");
	Hex B = Hex("ABC");
	Hex Result1 = Hex();


	Result1 = A + B;
	int output_int = Result1.get_int_i();
	std::cout << output_int << " ";
	std::cout << std::endl;
	for (int i = 0; i < Result1.get_size(); i++)
	{
		char output_char = Result1.get_char_i(i);
		std::cout << output_char << " ";
	}
	std::cout << std::endl;

	return 0;

}