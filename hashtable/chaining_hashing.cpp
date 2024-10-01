#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


using uint = unsigned int;

/**
 * 채이닝 방식은 부하율 계산 필요
 * 부하율 = 전체 키 개수 / 해시 테이블 크기
 * 모든 키가 같은 해시 값을 가질 경우 O(N) 걸림
 * 테이블이 너무 크면 메모리 낭비
 */
class hash_map
{
public:
    hash_map(size_t n)
    {
        data.resize(n);
    }

    void insert(uint const value)
    {
        int n = data.size();
        data[value % n].push_back(value);
        std::cout << value << "을(를) 삽입했습니다.\n";
    }

    bool find(uint value)
    {
        int n = data.size();
        auto& entries = data[value % n];
        return std::find(entries.begin(), entries.end(), value) != entries.end();
    }

    void erase(uint value)
    {
        int n = data.size();
        auto& entries = data[value % n];
        auto iter = std::find(entries.begin(), entries.end(), value);

        if (iter != entries.end())
        {
            entries.erase(iter);
        }
    }

private:
    std::vector<std::list<int>> data;
};


int main()
{
    hash_map map(7);

    auto print = [&](int const value)
    {
        if (map.find(value))
        {
            std::cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
        }
        else
        {
            std::cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
        }

        std::cout << '\n';
    };

    map.insert(2);
    map.insert(25);
    map.insert(10);

    map.insert(100);
    map.insert(55);

    print(100);
    print(2); //  collision
    
    map.erase(2);

    return 0;
}