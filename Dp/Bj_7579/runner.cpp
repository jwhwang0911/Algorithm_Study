#include<iostream>

using namespace std;

int index_of(int* array, int value) {
    
}

int main() {
    int N, M;
    // * M is required memory
    std::cin >> N >> M;
    int* Mem = new int[N];
    int* Costs = new int[N];   
    
    // * Input number of Memory and Costs
    for(size_t i = 0; i < N; i++) {
        cin >> Mem[i];
    }

    for(size_t i = 0; i < N; i++) {
        cin >> Costs[i];
    }

    int* DP_Costs = new int{N+1};

    for(size_t i = 0; i < M; i++ ) {
        if(i == 0) {
            DP_Costs[i] = 0;
            continue;
        }


    }
}