#include <iostream>
#include <queue>
#include <vector>

// 괄호 연산자를 오버로딩 했기 때문에 cmp의 객체를 함수처럼 사용할 수 있다.
class cmp
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main(void)
{
    std::priority_queue<int> pq;

    pq.push(-1);
    pq.push(8);
    pq.push(-7);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    std::cout << "기본 우선순위 큐의 pop: 내림차순으로 출력된다\n";
    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    std::priority_queue<int, std::vector<int>, cmp> custom_pq; // 비교 클래스는 3번째 템플릿 인자이므로 2번째 템플릿 인자도 명시를 해야한다.

    custom_pq.push(-1);
    custom_pq.push(8);
    custom_pq.push(-7);
    custom_pq.push(3);
    custom_pq.push(4);
    custom_pq.push(5);

    std::cout << "비교 클래스를 명시한 우선순위 큐의 pop: 오름차순으로 출력된다\n";
    while (!custom_pq.empty())
    {
        std::cout << custom_pq.top() << std::endl;
        custom_pq.pop();
    }

    return 0;
}