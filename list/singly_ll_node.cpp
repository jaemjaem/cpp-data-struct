#include <iostream>
#include <algorithm>

struct singly_ll_node
{
    int data;
    singly_ll_node* next;
};

class singly_ll
{
public:
    using node = singly_ll_node;
    using node_ptr = node*;

    struct singly_ll_iterator
    {
    public:
        singly_ll_iterator(node_ptr p) : ptr(p) {}

        int& operator*() { return ptr->data; }
        node_ptr get() { return ptr; }

        singly_ll_iterator& operator++()
        {
            ptr = ptr->next;
            return *this;
        }

        singly_ll_iterator& operator++(int)
        {
            singly_ll_iterator result = *this;
            ++(*this);

            return result;
        }

        friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right)
        {
            return left.ptr == right.ptr;
        }

        friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right)
        {
            return left.ptr != right.ptr;
        }
        
    private:
        node_ptr ptr;
    };


public:
    void push_front(int val)
    {
        auto new_node = new node {val, NULL};
        if (head != NULL)
            new_node->next = head;
        head = new_node;
    }

    void pop_front()
    {
        auto first = head;
        if (head)
        {
            head = head->next;
            delete first;
        }
    }

private:
    node_ptr head;
};
