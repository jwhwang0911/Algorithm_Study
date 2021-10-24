#include<iostream>
using namespace std;
int main() {

	int dp[31][31];

	for (int i = 1; i < 31; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			dp[i][j] = 0;
			for (int k = i-1; k <= j - 1; k++) {
				dp[i][j] = dp[i][j] + dp[i - 1][k];
			}
		}
	}

	int n;
	int a, b;
	cin >> n;

	while (n--) {
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}

}