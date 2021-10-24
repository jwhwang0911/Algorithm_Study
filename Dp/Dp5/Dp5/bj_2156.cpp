#include<iostream>
using namespace std;
int main() {
	int N;
	int lar = 0;
	cin >> N;
	int* jan = new int[N + 1];
	int* dp = new int[N + 1];
	jan[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> jan[i];
	}
	dp[0] = 0;
	dp[1] = jan[1];
	dp[2] = jan[1] + jan[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + jan[i], dp[i - 3] + jan[i - 1] + jan[i]);
	}
	for (int i = 1; i <= N; i++) {
		lar = lar > dp[i] ? lar : dp[i];
	}
	
	cout << lar;

}