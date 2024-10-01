#include <iostream>
#include <vector>


class hash_map
{
public:
    hash_map(int const n)
        : size(n)
    {
        data1 = std::vector<int>(n, -1);
        data2 = std::vector<int>(n, -1);
    }

    void insert(int const key)
    {
        insert_impl(key, 0, 1);
    }

    std::vector<int>::iterator lookup(int const key)
    {
        auto hash_value1 = hash1(key);

        if (data1[hash_value1] == key)
        {
            std::cout << "1�� ���̺��� " << key << "��(��) ã�ҽ��ϴ�.\n";
            return data1.begin() + hash_value1;
        }

        auto hash_value2 = hash2(key);

        if (data2[hash_value2] == key)
        {
            std::cout << "2�� ���̺��� " << key << "��(��) ã�ҽ��ϴ�.\n";
            return data2.begin() + hash_value2;
        }

        return data2.end();
    }

    void erase(int const key)
    {
        auto position = lookup(key);
        if (position != data2.end())
        {
            *position = -1;
            std::cout << key << "�� �ش��ϴ� ���Ҹ� �����߽��ϴ�.\n";
        }
        else
        {
            std::cout << key << "Ű�� ã�� ���߽��ϴ�.\n";
        }
    }

    void print()
    {
        std::cout << "Index : ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << i << '\t';
        }
        std::cout << '\n';

        std::cout << "Data1 : ";
        for (auto const i : data1)
        {
            std::cout << i << '\t';
        }
        std::cout << '\n';

        std::cout << "Data2 : ";
        for (auto const i : data2)
        {
            std::cout << i << '\t';
        }
        std::cout << '\n';
    }

private:
    int hash1(int const key) const
    {
        return key % size;
    }

    int hash2(int const key) const
    {
        return (key / size) % size;
    }

    void insert_impl(int const key, int const cnt, int const table)
    {
        if (cnt >= size)   
        {
            std::cout << key << " ���� �� ��ȯ �߻�! ���ؽ��� �ʿ��մϴ�!\n";
            return;
        }

        if (table == 1)
        {
            int hash = hash1(key);
            if (data1[hash] == -1)
            {
                std::cout << table << "���̺� " << key << "����.\n";
                data1[hash] = key;
            }
            else
            {
                int old = data1[hash];
                data1[hash] = key;
                std::cout << table << "�� ���̺� " << key << " ����: ������ " << old << " �̵� -> ";
                insert_impl(old, cnt + 1, 2);
            }
        }
        else
        {
            int hash = hash2(key);
            if (data2[hash] == -1)
            {
                std::cout << table << "���̺� " << key << "����.\n";
                data2[hash] = key;
            }
            else
            {
                int old = data2[hash];
                data2[hash] = key;
                std::cout << table << "�� ���̺� " << key << " ����: ������ " << old << " �̵� -> ";
                insert_impl(old, cnt + 1, 1);
            }
        }

    }

private:
    std::vector<int> data1;
    std::vector<int> data2;
    int size;
};


int main()
{
    hash_map map(7);

    map.print();
    std::cout << '\n';
    
    map.insert(10);
    map.insert(20);
    map.insert(30);
    std::cout << '\n';
    map.insert(104);
    map.insert(2);
    map.insert(70);
    map.insert(9);
    map.insert(90);
    map.insert(2);
    map.insert(7);
    std::cout << '\n';

    map.print();
    std::cout << '\n';

    map.insert(14); // ��ȯ �߻�
}