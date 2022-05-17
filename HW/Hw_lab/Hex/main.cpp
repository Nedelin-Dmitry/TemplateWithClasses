#include <iostream>
#include <fstream>
#include"Hex.h"

int main() {
    Hex A = Hex("FE1"); // the flip in converting decimal to hex //ABC//FE1 does not work
    Hex B = Hex("ABC"); // output char backwards


    std::cout << "A is : " << std::endl;
    write(A);
    std::cout << std::endl;

    try {
        Hex C = Hex("CBA");
        int input;
        std::cin >> input;
        std::cout << C[input] << std::endl;
    }
    catch (int _index) {
        if (_index == 1) { std::cout << "Out of range" << std::endl; }
        else if (_index == 2) { std::cout << "Invalid characters" << std::endl; }
    }
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

    // writing and reading to/from a file(-a)

    std::ofstream out;  // stream for recording
    out.open("Hex_Num.txt");  // opening the file to write Hex_Num - relative path
    out << Result1 << std::endl;


    std::ifstream in("Hex_Num.txt");
    Hex a = Hex();
    in >> a;
    write(a);

    return 0;

}