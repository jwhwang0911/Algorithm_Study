#include "student.h"
#include "dynamic_array.h"

std::ostream& operator<< (std::ostream &os, const Student &s) {
    return (os << "[" << s.name <<  ", " << s.standard << "]");
}

int main() {
    int nStudents;
    std::cout << "1반 학생수를 입력하세요 : ";
    std::cin >> nStudents;

    dynamic_array<Student> class1(nStudents);

    for(int i = 0; i < nStudents; i++) {
        std::string name;
        int standard;
        std::cout << i+1 << "번째 학생 이름과 나이를 입력하세요 : ";
        std::cin >> name >> standard;
        class1[i] = Student{name, standard};
    }

    try {
        class1.at(nStudents) = Student{"John", 8};
    }
    catch(...) {
        std::cout << "예외 발생" << std::endl;
    }

    auto class2 = class1;
    std::cout << "1반을 복사하여 2반을 생성 : " << class2.to_string() << std::endl;

    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << std::endl; 
}