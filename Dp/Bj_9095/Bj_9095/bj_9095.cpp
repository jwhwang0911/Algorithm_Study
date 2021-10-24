#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int* a = new int[N];
	int T[12];
	T[0] = 0;
	T[1] = 1;
	T[2] = 2;
	T[3] = 4;
	for (int i = 4; i <= 11; i++) {
		T[i] = T[i - 1] + T[i - 2] + T[i - 3];
	}
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cout << T[a[i]] << endl;
	}
}