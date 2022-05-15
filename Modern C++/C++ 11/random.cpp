#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

int randomInt_C(int min, int max)
{
    return rand() % (max - min + 1) + min; // rand()의 반환값을 [min, max] 범위로 변환
}

int randomInt_Cpp(int min, int max)
{
    // 시드와 엔진은 1회만 초기화 하기 위해 static 지역 변수로 선언
    static std::random_device rd;                      // 하드웨어적 요소를 이용한 랜덤시드
    static std::mt19937 mt(rd());                      // 랜덤 시드를 이용한 난수엔진 초기화
    std::uniform_int_distribution<int> dist(min, max); // [min, max] 범위의 균일 분포 정수 난수

    return dist(mt); // 생성된 난수 반환
}

double randomDouble_C()
{
    return rand() / (RAND_MAX + 1.0); // rand()의 반환값을 [0, 1) 범위로 변환
}

double randomDouble_Cpp()
{
    // 시드와 엔진은 1회만 초기화 하기 위해 static 지역 변수로 선언
    static std::random_device rd;                      // 하드웨어적 요소를 이용한 랜덤시드
    static std::mt19937 mt(rd());                      // 랜덤 시드를 이용한 난수엔진 초기화
    std::uniform_real_distribution<double> dist(0, 1); // [0, 1) 범위의 균일 분포 실수 난수

    return dist(mt); // 생성된 난수 반환
}

int main(void)
{
    srand(time(NULL)); // rand()의 시드로 값이 계속 변하는 현재 시간값을 사용한다.

    std::cout << "randomInt_C\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << randomInt_C(0, 10000) << std::endl;
    }

    std::cout << "randomInt_Cpp\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << randomInt_Cpp(0, 10000) << std::endl;
    }

    std::cout << "randomDouble_C\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << randomDouble_C() << std::endl;
    }

    std::cout << "randomDouble_Cpp\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << randomDouble_Cpp() << std::endl;
    }

    return 0;
}