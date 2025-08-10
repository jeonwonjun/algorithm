#include <iostream>
using namespace std;

int map[21][21][21];
int a,b,c;

int main() {
    for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
        for (int k = 0; k < 21; k++) {
            if (i == 0 || j == 0 || k == 0)
                map[i][j][k] = 1;
            else if (i < j && j < k) {
                map[i][j][k] = map[i][j][k-1] + map[i][j-1][k-1] - map[i][j-1][k];
            } else {
                map[i][j][k] = map[i-1][j][k] + map[i-1][j-1][k] + map[i-1][j][k-1] - map[i-1][j-1][k-1];
            }
        }
    }
}
    cin >> a >> b >> c;
    while (!(a == -1 && b == -1 && c == -1)) {
        if (a<=0 || b<=0 || c<=0) {
            printf("w(%d, %d, %d) = %d\n", a, b, c, map[0][0][0]);
        } else if (a > 20 || b > 20 || c > 20) {
            printf("w(%d, %d, %d) = %d\n", a, b, c, map[20][20][20]);  
        } else {
            printf("w(%d, %d, %d) = %d\n", a, b, c, map[a][b][c]);    
        }
        cin >> a >> b >> c;
    }
    return 0;
}