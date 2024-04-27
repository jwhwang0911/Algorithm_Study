#include<iostream>
#include<tuple>

using namespace std;

enum WORK {
    CONSTRUCT = 1,
    DESTROY
};

tuple<int, bool> flatten(int** const field, const int n, const int m, int block, const int min_time, const int cur_height) {
    int cost_time = 0;
    bool valid = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp = field[i][j];
            if(cur_height == temp) {
                continue;
            }
            else if(cur_height > temp) {
                cost_time += CONSTRUCT * (cur_height - temp);
                block -= (cur_height - temp);
            } else if(cur_height < temp) {
                cost_time += DESTROY * (temp - cur_height);
                block += (temp - cur_height);
            }
            if(cost_time > min_time) {
                return tuple<int, bool>(0, false);
            }
        }
    }

    valid = block < 0 ? false : true;
    tuple<int, bool>result = tuple<int, bool>(cost_time, valid);
    return result;
}

int main() {
    int n, m, b;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> b;
    int **field = new int*[n];
    int min_height = 256;
    int max_heihgt = 0;

    // min과 max hegiht <- for 반복문 시작 및 종료 조건
    for(int i = 0; i < n; i++) {
        field[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
            if( field[i][j] < 0 || field[i][j] > 256) {
                cerr << "Invalid height of field" << endl;
                return -1;
            }
            if( field[i][j] < min_height) {
                min_height = field[i][j];
            }
            if ( field[i][j] > max_heihgt) {
                max_heihgt = field[i][j];
            }
        }
    }

    tuple<int, bool> result;
    int min_time = (~0U >> 2);
    int height = min_height;
    for(int h = min_height; h <= max_heihgt; h++) {
        result = flatten(field, n, m, b, min_time, h);
        // cout << get<1>(result) <<"\t" << get<0>(result) << "\t" << h <<endl;

        if(get<1>(result)) {
            min_time = get<0>(result);
            height = h;
        }
    }

    cout << min_time << " " << height;

    for(int i = 0; i < n; i++) {
        delete[] field[i];
    }
    delete field;
}