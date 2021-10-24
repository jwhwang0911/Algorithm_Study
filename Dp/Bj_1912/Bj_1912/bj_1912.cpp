#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* narr = new int[n];
	int* dp = new int[n];
	int sum = -1000;

	for (int i = 0; i < n; i++) {
		cin >> narr[i];
		dp[i] = max(dp[i- 1] + narr[i], narr[i]);
		sum = max(dp[i], sum);
	}
	cout << sum << endl;
}