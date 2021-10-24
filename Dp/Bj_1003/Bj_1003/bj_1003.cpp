#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	int fibo_0[41];
	int fibo_1[41];
	int* Test = new int[T];

	fibo_0[0] = 1;
	fibo_0[1] = 0;
	fibo_1[0] = 0;
	fibo_1[1] = 1;

	for (int i = 2; i < 41; i++) {
		fibo_0[i] = fibo_0[i - 1] + fibo_0[i - 2];
		fibo_1[i] = fibo_1[i - 1] + fibo_1[i - 2];
	}
	for (int i = 0; i < T; i++) {
		cin >> Test[i];
	}

	for (int i = 0; i < T; i++) {
		cout << fibo_0[Test[i]] << " " << fibo_1[Test[i]] << endl;
	}

}