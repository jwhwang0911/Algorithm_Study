#include<iostream>
using namespace std;
int main() {
	int N, mini;
	cin >> N;
	int** ch = new int* [N + 1];
	for (int i = 0; i < N + 1; i++) {
		ch[i] = new int[5];
		for (int j = 0; j < 3; j++) {
			ch[i][j] = 1001;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch[i][j];
		}
	}


	for (int i = 1; i < N+1; i++) {
		for (int j = 0; j < 3; j++) {
			ch[i][j] = ch[i][j] + min(ch[i - 1][(3+j - 1)%3], ch[i - 1][(3+j + 1)%3]);
		}
	}

	mini = ch[N-1][1];
	for (int i = 0; i < 3; i++) {
		mini = ch[N-1][i] > mini ? mini : ch[N-1][i];
	}
	cout << mini;
	

	for (int i = 0; i < N; i++) {
		delete[] ch[i];
	}
	delete[] ch;
}