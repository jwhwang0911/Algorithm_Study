#include<iostream>

// 기본 자료형을 객체로써 다루어야 할 때 기본 자료형을 감싸서(warp) 사용할 수 있다. 
class Int {
    int data;

    public:
        Int(int data) : data(data) {}
        Int(const Int& i) : data(i.data) {}

        // 여기서 int변수가 가진 operator를 재정의 해도 됨. 근데 이제 그러면 너무 귀찮
        // 그래서 이런식으로 operator를 재정의 해서 사용할 수 있음.

        operator int() {
            return data;
        }
};

int main() {
  Int x = 3;
  int a = x + 4;

  x = a * 2 + x + 4;
  std::cout << x << std::endl;
}