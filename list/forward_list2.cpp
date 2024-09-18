#include <iostream>
#include <forward_list>
#include <vector>

int main()
{
    std::vector<std::string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", "Sebastian Vettel",  "Lewis Hamilton", "Sebastian Vettel", "Sebastian Vettel", "Sebastian Vettel",
        "Fernando Alonso"
    };

    auto it = vec.begin();
    std::cout << "���� �ֱ� ����� : " << *it << std::endl;

    it += 8;
    std::cout << "8�� �� ����� : " << *it << std::endl;

    std::advance(it, -3);
    std::cout << "���� 3�� �� ����� : " << *it << std::endl;

    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    auto it1 = fwd.begin();
    std::cout << "���� �ֱ� ����� : " << *it1 << std::endl;

    std::advance(it1, 5);
    std::cout << "5�� �� ����� : " << *it1 << std::endl;
}