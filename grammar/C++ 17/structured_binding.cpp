// C++ 17 기능을 사용하므로 아래와 같이 컴파일한다.
// g++- -std=c++17 if_init.cpp
#include <iostream>
#include <utility>
#include <string>
#include <tuple>

int main(void)
{
    // 바인딩할 개수는 대상의 요소의 개수와 같아야 한다.

    // 배열 바인딩
    int arr[] = {0, 1, 2};

    auto [x, y, z] = arr;

    std::cout << x << ' ' << y << ' ' << z << std::endl;

    // pair 바인딩
    std::pair<std::string, int> p = std::make_pair("test", 100);

    auto [s, i] = p;

    std::cout << s << ' ' << i << std::endl;

    // tuple 바인딩
    std::tuple<char, int, std::string> t = std::make_tuple('A', 1000, "hello");

    auto [c, ii, ss] = t; // get<0>(t)와 같이 컴파일 된다.

    std::cout << c << ' ' << ii << ' ' << ss << std::endl;

    return 0;
}