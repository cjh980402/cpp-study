// C++ 17 기능을 사용하므로 아래와 같이 컴파일한다.
// g++ -std=c++17 inline_variables.cpp
#include <iostream>

class InitTest
{
public:
    static const int static_const_member = 100; // 상수 static 멤버는 선언과 동시에 초기화가 가능하다.
    static int static_member;
    inline static int inline_static_member = 300; // inline을 사용시 일반 static 멤버도 선언과 동시에 초기화가 가능하다.
};

int InitTest::static_member = 200; // 일반 static 멤버는 외부에서 초기화를 해야한다.

int main(void)
{
    std::cout << "상수 static: " << InitTest::static_const_member
              << "\n일반 static: " << InitTest::static_member
              << "\ninline 일반 static: " << InitTest::inline_static_member;

    return 0;
}