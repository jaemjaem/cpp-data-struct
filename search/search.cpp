#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>


bool linear_search(int const N, const std::vector<int>& sequence)
{
    for (auto const i : sequence)
    {
        if (i == N)
        {
            return true;
        }
    }

    return false;
}


bool binary_search(int const N, const std::vector<int>& sequence)
{
    auto first = sequence.begin();
    auto last = sequence.end();

    while (true)
    {
        auto range_length = std::distance(first, last);

        auto mid_element_iter = first;
        std::advance(mid_element_iter, range_length / 2);

        auto mid_element = *mid_element_iter;


        if (mid_element == N)
        {
            return true;
        }
        else if (mid_element > N)
        {
            last = mid_element_iter;
        }
        else if (mid_element < N)
        {
            first = std::next(mid_element_iter);  
        }

        if (range_length == 1)
        {
            return false;
        }
    }
}

void run_large_search_test(int const size, int const N)
{
    std::vector<int> S; S.reserve(size);
    std::random_device rd;
    std::mt19937 rand(rd());

    std::uniform_int_distribution<std::mt19937::result_type> uniform_dis(1, size);

    for (auto i = 0; i < size; ++i)
    {
        S.push_back(uniform_dis(rand));
    }

    std::sort(S.begin(), S.end());

    auto binary_begin = std::chrono::steady_clock::now();

    bool binary_search_result = binary_search(N, S);

    auto binary_end = std::chrono::steady_clock::now();

    auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(binary_end - binary_begin);
    std::cout << "binary test time : " << diff1.count() << '\n';

    auto linear_begin = std::chrono::steady_clock::now();

    bool linear_search_result = linear_search(N, S);

    auto linear_end = std::chrono::steady_clock::now();

    auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(linear_end - linear_begin);
    std::cout << "linear test time : " << diff2.count() << '\n';

    if (binary_search_result)
    {
        std::cout << "binary found.\n";
    }
    else
    {
        std::cout << "binary not found.\n";
    }

    if (linear_search_result)
    {
        std::cout << "linear found.\n";
    }
    else
    {
        std::cout << "linear not found.\n";
    }
}

int main()
{
    run_large_search_test(100000, 36543);
    run_large_search_test(1000000, 36543);
    run_large_search_test(10000000, 36543);
        
    return 0;
}