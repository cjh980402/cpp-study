// C++ 17 기능을 사용하므로 아래와 같이 컴파일한다.
// g++ -std=c++17 if_init.cpp
#include <iostream>

int main(void)
{
    // if문의 조건식에서 변수 선언 + 조건식 사용
    std::cout << "Use variable initialize in if condition\n";
    if (int a = 10; a > 50)
    {
        std::cout << "then state\n";
    }
    else
    {
        std::cout << "else state\n";
    }

    // switch문의 조건식에서 변수 선언 + 조건식 사용
    std::cout << "\nUse variable initialize in switch condition\n";
    switch (int a = 10; 2 * a)
    {
    case 10:
        std::cout << "condition 10\n";
        break;
    case 20:
        std::cout << "condition 20\n";
        break;
    }

    return 0;
}