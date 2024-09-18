#include <array>
#include <iostream>
#include <type_traits>

template<typename ...Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type_t<Args...>, sizeof...(args)>
{
    using commonType = typename std::common_type_t<Args...>;
    return {std::forward<commonType>((Args&&)args)...};
}


int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);
    // auto data = build_array(1, "Packt", 2.0); // error code!

    for (auto i : data)
    {
        std::cout << i << ' ';
    }
}