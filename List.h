#ifndef CUSTOM_LIST_LIST_H
#define CUSTOM_LIST_LIST_H

#include <iostream>

#include "Node.h"
#include "person.h"

template<typename T>
class ForwardList
{
public:

    void push_back(const T&);
    void push_front(const T&);
    bool pop_back();
    bool pop_front();
    bool insert(const T&, size_t);
    bool remove(size_t);
    void clear();
    bool isEmpty();
    size_t getLength();
    Node<T>* getEntry(size_t);
    bool setEntry(size_t, Node<T>*);

    ~ForwardList()
    {
        clear();
    }

    void print() const; //only for TEST

    Node<T>* getHead() const { return m_head; }
    void setHead(Node<T>* node) { m_head = node; }

private:
    Node<T>* m_head{ nullptr };
};


template<typename T>
bool ForwardList<T>::isEmpty()
{
    return !getHead();
}

template<typename T>
size_t ForwardList<T>::getLength()
{
    size_t length{ 0 };
    Node<T>* cur = getHead();

    if (cur)
    {
        while (cur)
        {
            ++length;
            cur = cur->next;
        }
    }

    return length;
}

template<typename T>
void ForwardList<T>::push_back(const T& data)
{
    Node<T>* node = new Node<T>;
    node->data = data;

    if (!getHead())
    {
        setHead(node);
    }
    else {
        Node<T>* cur = getHead();
        while (cur->next)
            cur = cur->next;
        cur->next = node;
    }
}

template<typename T>
void ForwardList<T>::push_front(const T& data)
{
    Node<T>* node = new Node<T>;
    node->data = data;

    if (!getHead())
    {
        setHead(node);
    }
    else {
        node->next = getHead();
        setHead(node);
    }
}

template<typename T>
bool ForwardList<T>::insert(const T& data, size_t pos)
{
    if(pos < 0 || pos > getLength())
        return false;

    Node<T>* node = new Node<T>;
    node->data = data;
    Node<T>* p = getHead();

    if(0 == pos)
    {
        node->next = getHead();
        setHead(node);
    }
    else
    {
        for(size_t i=0;i<pos-1;i++)
            p=p->next;
        node->next = p->next;
        p->next = node;
    }

    return true;
}

template<typename T>
bool ForwardList<T>::pop_back()
{
    if (isEmpty())
        return false;

    Node<T>* cur{ getHead() };
    Node<T>* prev{ getHead() };

    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev == cur)
    {
        delete cur;
        setHead(nullptr);
        return true;
    }

    delete cur;
    prev->next = nullptr;

    return true;
}

template<typename T>
bool ForwardList<T>::pop_front()
{
    if (isEmpty())
        return false;

    if (getLength() > 1)
    {
        Node<T>* prev_head = getHead();
        setHead(getHead()->next);
        delete prev_head;
    }
    else
    {
        delete getHead();
        setHead(nullptr);
    }


    return true;
}

template<typename T>
bool ForwardList<T>::remove(size_t pos)
{
    if (isEmpty())
        return false;


    Node<T>* cur{ getHead() };
    Node<T>* prev{ nullptr };

    if (!pos)
    {
        pop_front();
        return true;
    }

    while (pos)
    {
        prev = cur;
        cur = cur->next;

        if (!cur)
            return false;

        --pos;
    }

    Node<T>* next = cur->next;
    delete cur;
    prev->next = next;

    return true;

}

template<typename T>
void ForwardList<T>::clear()
{
    while (getHead())
        pop_back();
}

template<typename T>
Node<T>* ForwardList<T>::getEntry(size_t pos)
{
    if (isEmpty())
    {
        std::cout << "List is Empty!!" << std::endl;
        return nullptr;
    }

    Node<T>* cur{ getHead() };
    while (pos)
    {
        cur = cur->next;

        if (!cur)
        {
            std::cout << "Enter valid position!!" << std::endl;
            return nullptr;
        }

        --pos;
    }

    return cur;
}

template<typename T>
bool ForwardList<T>::setEntry(size_t pos, Node<T>* node)
{
    if (isEmpty())
        return false;

    if (getEntry(pos))
    {
        Node<T>* cur = getEntry(pos);
        cur->data = node->data;
    }
    else
        return false;

    return true;
}


// for test
template<typename T>
void ForwardList<T>::print() const
{
    Node<T>* tmp = getHead();
    while (tmp)
    {
        tmp->data.print();
        tmp = tmp->next;
    }
}

#endif //CUSTOM_LIST_LIST_H