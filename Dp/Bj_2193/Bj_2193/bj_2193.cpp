#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long int* bi = new long long int[n];
	bi[0] = 1;
	bi[1] = 1;
	for (int i = 2; i < n; i++) {
		bi[i] = bi[i-1]+bi[i-2]; // 10�ϰ� ������ 1�̳������� 0�� �������� �� �Ǵ�
	}
	cout << bi[n - 1];
}