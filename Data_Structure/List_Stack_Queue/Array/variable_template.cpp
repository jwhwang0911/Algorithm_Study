#include<iostream>
#include<string>

// 가변 길이 print (마치 python 처럼)
template<typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

/*
override를 활용한 이런 방법도 있음을 인지 (재귀를 이용)

template <typename T, typename... Types>
void print(T arg, Types... args) {
  std::cout << arg << ", ";
  print(args...);
}
*/

template<typename T, typename... Types>
void print(T arg, Types... args) {
    std::cout << arg << ",";
    ((std::cout << args << " "), ...) << std::endl;
    // 오른쪽으로 확장하면서 이짓거리를 하겠다는 뜻
}

// 임의의 개수의 문자열을 합치는 함수
template<typename str>
void StrCat(const str& s) {
    return std::string(s);
}

template<typename str, typename... strs>
void StrCat(const str& s, const strs&... ss) {
    
}

int main() {
    print("1", 3.1, "abc");
    print(1, 2, 3, 4, 5, 6, 7);
}