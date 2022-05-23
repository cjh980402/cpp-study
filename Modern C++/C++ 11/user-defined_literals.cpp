#include <iostream>
using namespace std;

// 사용자 정의 리터럴은 무조건 언더바로 시작해야 한다.
// 함수 선언과 같은 방식이기 때문에 반환형이 auto일 필요는 없다.

auto operator"" _hello(const char *s, size_t len)
{
    cout << "string literal" << endl;
    return s;
}

auto operator"" _hello(unsigned long long s)
{
    cout << "integer literal" << endl;
    return s;
}

auto operator"" _hello(long double s)
{
    cout << "real number literal" << endl;
    return s;
}

auto operator"" _hello(char s)
{
    cout << "char literal" << endl;
    return s;
}

int main()
{
    cout << "HI"_hello << endl;
    cout << 3_hello << endl;
    cout << 30.5_hello << endl;
    cout << 'A'_hello << endl;

    return 0;
}