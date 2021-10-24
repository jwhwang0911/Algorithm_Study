#include<iostream>
using namespace std;
int main() {
	int n;
	int dp[1001];
	cin >> n;

	// 0이면 상근 승, 1이면 창영 승

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	for (int i = 5; i < 1001; i++) {
		if (min(dp[i - 1], dp[i - 3]) == 1) {
			dp[i] = 0;
		}
		else {
			dp[i] = 1;
		}
	}
	if (dp[n] == 1) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
}