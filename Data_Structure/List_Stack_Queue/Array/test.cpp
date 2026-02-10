#include "student.h"

std::ostream& operator<< (std::ostream &os, const Student &s) {
    return (os << "[" << s.name <<  ", " << s.standard << "]");
}
