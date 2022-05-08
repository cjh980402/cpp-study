#include <iostream>

class mySuper
{
public:
    void notVirtual()
    {
        std::cout << "This is notVirtual of mySuper" << std::endl;
    }
    virtual void print() = 0; // 순수 가상 함수
};

void mySuper::print()
{
    // 순수 가상 함수여도 함수의 구현을 할 수 있다.
    // 여전히 객체 생성은 불가능하지만 하위 클래스에서 mySuper의 print()를 호출할 수 있게 된다.
    std::cout << "This is print of mySuper" << std::endl;
}

class mySub : public mySuper
{
public:
    void notVirtual()
    {
        std::cout << "This is notVirtual of mySub" << std::endl;
    }
    virtual void print()
    {
        mySuper::print(); // 상위 클래스의 메소드 호출
        std::cout << "This is print of mySub" << std::endl;
    }
};

int main(void)
{
    // mySuper sup; // print()가 순수 가상 함수이므로 mySuper의 객체를 생성할 수 없다.
    mySub sub;
    sub.notVirtual(); // mySub의 메소드가 호출된다.
    sub.print();      // mySub의 메소드가 호출된다.

    mySuper &rsup = sub;
    rsup.notVirtual(); // mySuper의 메소드가 호출된다.
    rsup.print();      // mySub의 메소드가 호출된다.

    // 가상함수는 동적 바인딩이 일어나기 때문에 상위 클래스의 포인터나 참조로 하위 클래스를 가리켜도 하위 클래스의 메소드를 호출한다.

    return 0;
}