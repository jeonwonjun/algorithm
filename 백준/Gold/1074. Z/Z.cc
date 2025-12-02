#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int total_size;

int main() {
    cin >> N >> r >> c;
    total_size = pow(2, N);
    int answer = 0;
    int dir = 0;
    int half;
    
    while (total_size > 1) {
        half = total_size / 2;
        
        // 1. (r, c) 위치 찾기
        if (r < half && c < half) {
            dir = 0;
        } else if (r < half && c >= half) {
            dir = 1;
            c -= half;
        } else if (r >= half && c < half) {
            dir = 2;
            r -= half;
        } else if (r >= half && c >= half) {
            dir = 3;
            r -= half;
            c -= half;
        }
    
        answer += dir*half*half;
    
        total_size = half;
    }
    cout << answer <<'\n';


    return 0;
}