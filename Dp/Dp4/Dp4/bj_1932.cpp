#include<iostream>
using namespace std;
int main() {
	
	int h,big;
	cin >> h;
	int** tri = new int* [h+2];
	for (int i = 0; i < h+2; i++) {
		tri[i] = new int[h+2];
		for (int j = 0; j < h + 2; j++) {
			tri[i][j] = 0;
		}
	} // 이차원 배열 동적할당

	//입력
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	// 입력받은거 출력
	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < h + 2; j++) {
			cout << tri[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//최댓값
	for (int i = 1; i < h + 2; i++) {
		for (int j = 1; j < h + 2; j++) {
			tri[i][j] = tri[i][j] + max(tri[i - 1][j - 1], tri[i - 1][j]);
		}
	}

	// 입력받은거 출력
	for (int i = 0; i < h + 1; i++) {
		for (int j = 0; j < h + 2; j++) {
			cout << tri[i][j] << "\t";
		}
		cout << endl;
	}

	big = 0;
	for (int i = 1; i < h + 1; i++) {
		big = big > tri[h+1][i] ? big : tri[h+1][i];
	}

	cout << endl << big;

	//해제
	for (int i = 0; i < h + 2; i++) {
		delete[] tri[i];
	}
	delete[] tri;
}