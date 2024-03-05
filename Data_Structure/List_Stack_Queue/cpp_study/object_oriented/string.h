#include <string.h>
#include <iostream>
class MyString {
    public:
        // explicit 키워드를 추가하면 암시적 변화를 할 수 없도록 컴파일러에게 명령 할 수 있음
        // 가령 explicit int x= 3을 한 이후에 func(std::string st)  <- func(x)를 하게 될 경우 오류 발생

        // mutable로 class의 변수들을 선언하면 const 함수에서도 변경가능
        // 명시적으로 const해야하는 함수이지만, 일부의 변수들의 변경이 성능을 좌우할 때 mutable 데이터로 선언하여 변경할 수 있음
        MyString(char c);
        MyString(const char *str);
        MyString(const MyString& str);

        ~MyString();
        int length() const;
        void println() const;

        MyString& assign(const char* str);
        MyString& assign(const MyString& str);

        int capacity() const;
        void reserve(const int size);
        char at(int pos);

        MyString& insert(int pos, const char c);
        MyString& insert(int pos, const char* str);
        MyString& insert(int pos, MyString str);
        MyString& erase(int pos, int num);

        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
        int find(int find_from, MyString& str) const;

        int compare(const MyString& str) const;

        bool operator==(MyString& str) {
            return !this->compare(str);
        }

        // operator for +, +=, []

    private:
        char *content;
        int str_length;
        int memory;
};