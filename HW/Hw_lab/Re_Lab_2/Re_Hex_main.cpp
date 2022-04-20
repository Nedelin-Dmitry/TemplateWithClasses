#include <iostream>
#include <fstream>
#include"Re_Hexr.h"

/*
 Косяки:
 1) !корректное чтение из файла
*/
int main()
{
	Hex A = Hex("FE1"); // не работает переворот в преобразовании десятиричного в hex //ABC //FE1
	Hex B = Hex("ABC"); // вывод char задом наперёд

	std::cout <<"A is : " << std::endl;
	write(A);
	std::cout << std::endl;

	std::cout << "B is : " << std::endl;
	write(B);
	std::cout << std::endl;

	Hex Result1 = Hex();


	Result1 = A + B;
	std::cout << "A + B: " << std::endl;
	write(Result1);
	std::cout << std::endl;

	Hex Result2 = Hex();
	
	Result2 = A - B;
	std::cout << "A - B: " << std::endl;
	write(Result2);
	std::cout << std::endl;

	Result2 = A - A;
	std::cout << "A - A: " << std::endl;
	write(Result2);
	std::cout << std::endl;

	Result2 = B - A;
	std::cout << "B - A: " << std::endl;
	write(Result2);
	std::cout << std::endl;

	Hex Result3 = Hex();

	Result3 = A * B;
	std::cout << "A * B: " << std::endl;
	write(Result3);
	std::cout << std::endl;
	
	Hex Result4 = Hex();

	Result4 = A * 5;
	std::cout << "A * 5: " << std::endl;
	write(Result4);
	std::cout << std::endl;

	// >
	bool result = A > B;
	std::cout << "A > B?  " << result << std::endl;
	
	result = B > A;
	std::cout << "B > A?  " << result << std::endl;
	std::cout << std::endl;

	// <
	result = A < B;
	std::cout << "A < B?  " << result << std::endl;

	result = B < A;
	std::cout << "B < A?  " << result << std::endl;
	std::cout << std::endl;

	// >=
	result = A >= B;
	std::cout << "A >= B? " << result << std::endl;

	result = B >= A;
	std::cout << "B >= A? " << result << std::endl;

	result = A >= A;
	std::cout << "A >= A? " << result << std::endl;
	std::cout << std::endl;

	// <=
	result = A <= B;
	std::cout << "A <= B? " << result << std::endl;

	result = B <= A;
	std::cout << "B <= A? " << result << std::endl;

	result = A <= A;
	std::cout << "A <= A? " << result << std::endl;
	std::cout << std::endl;

	// !=
	result = A != A;
	std::cout << "A != A? " << result << std::endl;

	result = A != B;
	std::cout << "A != B? " << result << std::endl;
	std::cout << std::endl;

	// ==
	result = A == A;
	std::cout << "A == A? " << result << std::endl;

	result = A == B;
	std::cout << "A == B? " << result << std::endl; 
	std::cout << std::endl;

	// запись и чтение в/из файл(-a)

	std::ofstream out;          // поток для записи
	out.open("Hex_Num.txt"); // открываем файл для записи Hex_Num - относительный путь
	out << Result1 << std::endl;


	std::ifstream in("Hex_Num.txt");
	Hex a = Hex();
	in >> a;
	for (int i = 0; i < a.get_size(); i++)
	{
		std::cout << a.get_char_i(i);
	}
	std::cout << std::endl;
	return 0;

}