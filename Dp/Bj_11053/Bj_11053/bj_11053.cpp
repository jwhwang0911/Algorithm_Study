#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	int* dp = new int[N];
	int sum=0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1); // �� ���� ��(j)�� ������ �ٷ� �ڿ� (i)�� �´ٰ� ����
			}
		}
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;

}