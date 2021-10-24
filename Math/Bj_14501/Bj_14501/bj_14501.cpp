#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* T = new int[n + 1];
	int* P = new int[n + 1];
	int* dp = new int[n + 2];
	int maximum = 0;

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
		dp[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		maximum = max(maximum, dp[i+1]);
	}
	cout << maximum;
}