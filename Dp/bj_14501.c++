#include<iostream>

using namespace std;
int main() {
    int N;
    cin >> N;
    int *T = new int[N+1];
    int *P = new int[N+1];
    int *C = new int[N+2];
    // C의 index 1 = 1일차

    for(int i = 1; i <=N ; i++) {
        cin >> T[i] >> P[i];
        C[i] = 0;
    }
    C[N+1] = 0;

    for(int i = 1; i <= N ; i++) {
        if (i + T[i] > N+1) {
            continue;
        }
        else {
            for(int t = i+T[i]; t <= N; t++) {
                C[t] = C[t] >= C[i] + P[i] ? C[t] : C[i] + P[i] ;
            }
        }
    }

    for(int i = 1; i<=N+1; i++) {
        cout << C[i] << "\t";
    }
}