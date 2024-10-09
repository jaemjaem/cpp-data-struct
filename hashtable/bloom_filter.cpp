#include <iostream>
#include <vector>

#include <assert.h>

class bloom_filter
{
public:
    bloom_filter(int const n)
        : nBits_{n}
    {
        data_= std::vector<bool>(nBits_, false);
    }

    void lookup(int const key)
    {
        bool result = data_[hash(0, key)] & data_[hash(1, key)] & data_[hash(2, key)];

        if (result)
        {
            std::cout << key << ": 있을 수 있음" << std::endl;
        }
        else
        {
            std::cout << key << ": 절대 없음" << std::endl;
        }
    }

    void insert(int const key)
    {
        data_[hash(0, key)] = true;
        data_[hash(1, key)] = true;
        data_[hash(2, key)] = true;
        std::cout << key << "을(를) 삽입: ";

        for (auto const a : data_)
        {
            std::cout << a << ' ';
        }

        std::cout << '\n';
    }

private:
    int hash(int const num, int const key)
    {
        switch (num)
        {
        case 0:
            return key % nBits_;
        
        case 1:
            return (key / 7) % nBits_;
        
        case 2:
            return (key / 11) % nBits_;
        
        default:
            assert("valid num");
            return -1;
        }
    }

private:
    std::vector<bool> data_;
    int nBits_;
};


int main()
{
    bloom_filter bf(7);
    bf.insert(100);
    bf.insert(54);
    bf.insert(82);

    bf.lookup(5);
    bf.lookup(50);
    bf.lookup(20);
    bf.lookup(54);
}