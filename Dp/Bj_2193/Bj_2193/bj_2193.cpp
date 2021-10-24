#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long int* bi = new long long int[n];
	bi[0] = 1;
	bi[1] = 1;
	for (int i = 2; i < n; i++) {
		bi[i] = bi[i-1]+bi[i-2]; // 10하고 다음에 1이나오는지 0이 나오는지 잘 판단
	}
	cout << bi[n - 1];
}