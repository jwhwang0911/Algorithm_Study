#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

struct Student {
    std::string name;
    int standard;
};

std::ostream& operator<< (std::ostream &os, const Student &s);

#endif // STUDENT_H
