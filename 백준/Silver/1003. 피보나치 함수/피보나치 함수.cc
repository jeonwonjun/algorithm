#include <iostream>

using namespace std;

int d[41][2];

int main() {
    int T;
    cin >> T;
    
    d[0][0] = 1, d[0][1] = 0;
    d[1][0] = 0, d[1][1] = 1;
    d[2][0] = 1, d[2][1] = 1;
    for (int i=3; i<=40; i++) {
        d[i][0] = d[i-1][0] + d[i-2][0];
        d[i][1] = d[i-1][1] + d[i-2][1];
    }
    
    while(T--) {
        int N;
        cin >> N;
        cout << d[N][0] << ' ' << d[N][1] << '\n';
    }
    
    return 0;
}
