#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>


class Student
{
public:
    Student(int const first_name, int const last_name, bool const vaccinated)
        : name_{std::make_pair(first_name, last_name)}, vaccinated_{vaccinated}
    {}

    auto get_name() const { return name_; }
    auto is_vaccinated() const { return vaccinated_; }

    bool operator<(const Student& other) const
    {        
        return this->name_ < other.name_;
    }

    bool operator>(const Student& other) const
    {        
        return this->name_ > other.name_;
    }

    bool operator==(const Student& other) const
    {        
        return this->name_ == other.name_;
    }

private:
    std::pair<int, int> name_;
    bool vaccinated_;
};


bool binary_search(Student p, const std::vector<Student>& sequence)
{
    auto first = sequence.begin();
    auto last = sequence.end();

    while (true)
    {
        auto range_length = std::distance(first, last);

        auto mid_element_iter = first;
        std::advance(mid_element_iter, range_length / 2);

        auto mid_element = *mid_element_iter;


        if (mid_element == p && mid_element.is_vaccinated() == false)
        {
            return true;
        }
        else if (mid_element == p && mid_element.is_vaccinated() == true)
        {
            return false;
        }
        else if (mid_element > p)
        {
            last = mid_element_iter;
        }
        else if (mid_element < p)
        {
            first = std::next(mid_element_iter);  
        }

        if (range_length == 1)
        {
            return false;
        }
    }
}

auto generate_random_student(int const max)
{
    std::random_device rd;
    std::mt19937 rand(rd());

    std::uniform_int_distribution<std::mt19937::result_type> uniform_dis(1, max);

    bool is_vaccinated = uniform_dis(rand) % 2 ? true : false;

    return Student(uniform_dis(rand), uniform_dis(rand), is_vaccinated);
}

void search_test(int const size, Student p)
{
    std::vector<Student> students;

    for (auto i = 0; i < size; ++i)
    {
        students.push_back(generate_random_student(size));
    }

    std::sort(students.begin(), students.end());

    auto binary_begin = std::chrono::steady_clock::now();

    bool binary_search_result = binary_search(p, students);

    auto binary_end = std::chrono::steady_clock::now();

    auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(binary_end - binary_begin);
    std::cout << "students search time : " << diff1.count() << '\n';

    if (binary_search_result)
    {
        std::cout << "need to vacc.\n";
    }
    else
    {
        std::cout << "dont need to vacc.\n";
    }
}


int main()
{
    auto p = generate_random_student(1000);

    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);

    return 0;
}