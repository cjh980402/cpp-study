// C++ 20 기능을 사용하므로 아래와 같이 컴파일한다.
// g++-11 -std=c++2a 3-way_comparison_operator.cpp
#include <iostream>

int main(void)
{
    // <=> 연산자의 반환값은 정수값이 아니지만 비교 연산자에 대해 오버로딩 되어있는 클래스를 반환한다.
    // <=> 연산자 한 번의 호출을 통해 <, ==, >에 대한 비교 결과를 한 번에 알 수 있다.
    // 아래의 세 식은 모두 true를 반환한다.
    std::cout << ((-10 <=> 10) < 0) << std::endl;
    std::cout << ((10 <=> 10) == 0) << std::endl;
    std::cout << ((100 <=> 10) > 0) << std::endl;

    return 0;
}