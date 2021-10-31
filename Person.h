#ifndef CUSTOM_LIST_PERSON_H
#define CUSTOM_LIST_PERSON_H

#include <iostream>

struct Person
{
public:
    Person& operator=(const Person&) = default;
    Person() : m_absence_count{}, m_salary{}, m_members_count{}, m_place_of_birth{}, m_surname{} {}
    Person(std::string surname, size_t members_count,
           size_t salary, size_t absence_count,
           std::string place_of_birth) : m_surname        {surname},
                                         m_members_count  {members_count},
                                         m_salary         {salary},
                                         m_absence_count  {absence_count},
                                         m_place_of_birth {place_of_birth} {}
    void print() {
        std::cout << "Person surname is: "        << m_surname        << std::endl;
        std::cout << "Person members count is: "  << m_members_count  << std::endl;
        std::cout << "Person salary is: "         << m_salary         << std::endl;
        std::cout << "Person absence count is: "  << m_absence_count  << std::endl;
        std::cout << "Person place of birth is: " << m_place_of_birth << std::endl;
    }
private:
    std::string m_surname        { };
    size_t      m_members_count  { };
    size_t      m_salary         { };
    size_t      m_absence_count  { };
    std::string m_place_of_birth { };
};

#endif //CUSTOM_LIST_PERSON_H