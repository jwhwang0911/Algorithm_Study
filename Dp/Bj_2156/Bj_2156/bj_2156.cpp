#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* po = new int[n];
	int* dp = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> po[i];
		if (i == 0) dp[i] = po[i];
		else if (i <= 2) {
			dp[i] = dp[i - 1] + po[i];
		}
		else {
			dp[i] = max(dp[i - 3] + po[i - 1] + po[i], dp[i - 2] + po[i]);
			dp[i] = max(dp[i],dp[i-1]);
		}
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;
}