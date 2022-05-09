#include <iostream>

class mySuper1
{
    int a;

public:
    virtual void print()
    {
        std::cout << "This is print of mySuper1" << std::endl;
    }
};

class mySub1 : public mySuper1
{
    int b;

public:
    virtual void print()
    {
        std::cout << "This is print of mySub1" << std::endl;
    }
};

class mySuper2
{
    int a;

public:
    void print()
    {
        std::cout << "This is print of mySuper2" << std::endl;
    }
};

class mySub2 : public mySuper2
{
    int b;

public:
    void print()
    {
        std::cout << "This is print of mySub2" << std::endl;
    }
};

int main(void)
{
    std::cout << "int 형의 크기: " << sizeof(int) << "바이트\n";

    // mySuper1: int 1개 + __vfptr = 4바이트(__vfptr에 맞춰서 8바이트로 패딩) + 8바이트 = 16바이트
    // mySub1: int 2개 + __vfptr = 8바이트 + 8바이트 = 16바이트
    std::cout << "가상함수가 있는 클래스의 크기\nmySuper1: " << sizeof(mySuper1) << "바이트, mySub1: " << sizeof(mySub1) << "바이트\n";

    // mySuper2: int 1개 = 4바이트
    // mySub2: int 2개 = 8바이트
    std::cout << "가상함수가 없는 클래스의 크기\nmySuper2: " << sizeof(mySuper2) << "바이트, mySub2: " << sizeof(mySub2) << "바이트\n";

    // 같은 구성으로 이루어진 클래스여도 가상함수가 존재하는 클래스의 크기가 더 크다.
    // 이러한 클래스의 내부에는 가상함수 테이블을 가리키는 숨은 포인터(__vfptr)가 존재하기 때문이다.
    // 가상함수 테이블은 각 타입 별로 존재한다.

    return 0;
}