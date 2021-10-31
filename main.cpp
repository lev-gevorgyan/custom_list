#include <iostream>

#include "Node.h"
#include "Person.h"
#include "List.h"

int main() {
    ForwardList<Person> l;
    l.push_back(Person("A", 9, 8, 7, "a"));
    l.push_back(Person("C", 11, 10, 9, "c"));
    l.insert(Person("B", 10, 9, 7, "b"), 1);
    l.print();
    return 0;
}
