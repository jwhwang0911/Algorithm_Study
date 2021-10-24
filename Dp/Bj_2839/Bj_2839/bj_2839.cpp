#include<iostream>
using namespace std;
int main() {
	
	int N;
	cin >> N;
	int *sugar = new int[N + 6];
	sugar[0] = 0;
	sugar[1] = 2000;
	sugar[2] = 2000;
	sugar[3] = 1;
	sugar[4] = 2000;
	sugar[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (sugar[i - 3] != 2000 || sugar[i - 5] != 2000) {
			sugar[i] = min(sugar[i - 3] + 1, sugar[i - 5] + 1);
		}
		else sugar[i] = 2000;
	}
	if (sugar[N] == 2000) {
		cout << "-1";
	}
	else cout << sugar[N];

}