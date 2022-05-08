#include <iostream>

class mySuper1
{
public:
    mySuper1()
    {
        std::cout << "mySuper1의 생성자\n";
    }

    ~mySuper1()
    {
        std::cout << "mySuper1의 소멸자\n";
    }
};

class mySub1 : public mySuper1
{
public:
    mySub1()
    {
        std::cout << "mySub1의 생성자\n";
    }

    ~mySub1()
    {
        std::cout << "mySub1의 소멸자\n";
    }
};

class mySuper2
{
public:
    mySuper2()
    {
        std::cout << "mySuper2의 생성자\n";
    }

    virtual ~mySuper2()
    {
        std::cout << "mySuper2의 소멸자\n";
    }
};

class mySub2 : public mySuper2
{
public:
    mySub2()
    {
        std::cout << "mySub2의 생성자\n";
    }

    virtual ~mySub2()
    {
        std::cout << "mySub2의 소멸자\n";
    }
};

int main(void)
{
    std::cout << "비가상 소멸자 + 하위 클래스 포인터로 참조\n";
    mySub1 *psub1 = new mySub1();
    delete psub1;

    std::cout << "비가상 소멸자 + 상위 클래스 포인터로 참조\n";
    mySuper1 *psup1 = new mySub1();
    delete psup1;

    std::cout << "가상 소멸자 + 하위 클래스 포인터로 참조\n";
    mySub2 *psub2 = new mySub2();
    delete psub2;

    std::cout << "가상 소멸자 + 상위 클래스 포인터로 참조\n";
    mySuper2 *psup2 = new mySub2();
    delete psup2;

    // 소멸자가 가상이어야만 상위 클래스로 참조를 했을 때도 하위 클래스의 소멸자까지 정상적으로 호출된다.
    // 상속을 염두해둔 클래스라면 소멸자를 가상으로 선언해야한다.
    // 정상적인 호출 순서: 상위 클래스 생성자 -> 하위 클래스 생성자 -> ... -> 하위 클래스 소멸자 -> 상위 클래스 소멸자

    return 0;
}