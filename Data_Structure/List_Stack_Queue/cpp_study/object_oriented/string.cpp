#include "string.h"

MyString::MyString(char c) {
    content = new char[1];
    content[0] = c;
    str_length = 1;
    memory = 1;
}

MyString::MyString(const char *str) {
    str_length = strlen(str);
    memory = str_length;
    content = new char[str_length];
    for(int i = 0; i < str_length; i++) content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    str_length = str.str_length;
    memory = str.str_length;
    content = new char[str_length];
    for(int i = 0; i< str_length; i++) content[i] = str.content[i];
}

MyString::~MyString() {
    delete[] content;
}

int MyString::length() const {return str_length;}

void MyString::println() const {
    for(int i = 0; i < str_length; i++) {
        std::cout << this->content[i];
    }

    std::cout << std::endl;
}
// *메모리 효율을 이용한 assign함수 (객체와 char * 모두의 경우)
MyString& MyString::assign(const char* str) {
    this->str_length = strlen(str);
    if( memory < str_length) {
        delete[] content;
        content = new char[str_length];
    }
    for(int i = 0; i < str_length; i++) {
        content[i] = str[i];
    }

    return *this;
}

MyString& MyString::assign(const MyString& str) {
    this->str_length = str.str_length;
    if(this->memory < this->str_length) {
        delete[] content;
        content = new char[this->str_length];
    }

    for(int i = 0; i < this->str_length; i++) this->content[i] = str.content[i];
    return *this;
}

// capacity도 이용
int MyString::capacity() const { return memory; }
// *size만큼 memory를 할당해주는 함수
void MyString::reserve(const int size) {
    if(size < this->memory ) {
        return;
    }
    this->memory = size;
    char* prev_str = this->content;
    this->content = new char[size];
    for(int i = 0; i < this->str_length; i++) this->content[i] = prev_str[i];
    delete[] prev_str;            
}
// at
char MyString::at(int pos) {
    if ( pos > this->str_length ) {
        exit(-1);
    }
    return this->content[pos];
}
// insert
MyString& MyString::insert(int pos, const char c) {
    MyString temp(c);
    return insert(pos, temp);
}

MyString& MyString::insert(int pos, const char* str) {
    MyString temp(str);
    return insert(pos, temp);
}

// *pos위치의 앞에 str을 insert
MyString& MyString::insert(int pos, MyString str) {
    char* prev_str = new char[this->str_length];
    for(int i = 0; i < this->str_length; i++) {
        prev_str[i] = this->content[i];
    }

    
    if (memory < this->str_length + str.str_length)
    {
        if(memory*2 > this->str_length + str.str_length) this->reserve(memory*2);
        else this->reserve(this->str_length + str.str_length);
    }

    int j;

    for(int i = 0; i < this->str_length; i++) {
        if(i < pos-1) this->content[i] = prev_str[i];
        else if(i == pos-1) {
            for(j = 0; j < str.str_length; j++) {
                this->content[i+j] = str.content[j];
            }
            this->content[i+j] = prev_str[i];
        }
        else this->content[i+j] = prev_str[i];
    }
    this->str_length = this->str_length + str.str_length;
    delete[] prev_str;
    
    return *this;
}

// *pos 부터 num길이만큼 삭제
MyString& MyString::erase(int pos, int num) {
    if(num < 0 || pos < 0 || pos > this->str_length) return *this;
    int deleted = 0;
    for(int i = pos; i < pos + num && i < this->str_length; i++) {
        if(i+num < this->str_length){
            this->content[i] = this->content[i+num];
        }
        deleted++;
    }
    this->str_length -= deleted;

    return *this;
}


// find
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if (str.str_length == 0) return -1;
    for (i = find_from; i <= str_length - str.str_length; i++) {
        for (j = 0; j < str.str_length; j++) {
        if (content[i + j] != str.content[j]) break;
        }

        if (j == str.str_length) return i;
    }

    return -1;  // 찾지 못했음
}

int MyString::compare(const MyString& str) const {
    // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
    // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
    // 이 같다는 의미, -1 은 (*this) 가 사전식으로 더 앞에 온다는 의미이다.

    for (int i = 0; i < std::min(str_length, str.str_length); i++) {
        if (content[i] > str.content[i])
        return 1;

        else if (content[i] < str.content[i])
        return -1;
    }

    // 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
    // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

    if (str_length == str.str_length) return 0;

    // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
    else if (str_length > str.str_length)
        return 1;

    return -1;
    }