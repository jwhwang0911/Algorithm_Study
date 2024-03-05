#include "string.h"

int main() {
  MyString str1("a word");
  MyString str2("sentence");
  MyString str3("sentence");

  if (str1 == str2)
    std::cout << "str1 와 str2 같다." << std::endl;
  else
    std::cout << "st1 와 str2 는 다르다." << std::endl;

  if (str2 == str3)
    std::cout << "str2 와 str3 는 같다." << std::endl;
  else
    std::cout << "st2 와 str3 는 다르다" << std::endl;
}