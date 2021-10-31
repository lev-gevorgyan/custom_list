#ifndef CUSTOM_LIST_NODE_H
#define CUSTOM_LIST_NODE_H

template<typename T>
struct Node
{
    T data;
    Node<T>* next{ nullptr };
};

#endif //CUSTOM_LIST_NODE_H