#include <iostream>
#include <vector>
using namespace std;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    vector<string> board(r);
    for (int i=0;i<r;i++) cin >> board[i];

    vector<vector<int>> a(r, vector<int>(c,0));
    vector<vector<int>> b(r, vector<int>(c,0));
    
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (board[i][j] == 'O') {
                for (int dir=0; dir<5; dir++) {
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if (0<=nx && nx<r && 0<=ny && ny<c) {
                        a[nx][ny] = 1;
                    }
                }
            }
        }
    }
    
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (a[i][j] == 0) {
                for (int dir=0; dir<5; dir++) {
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if (0<=nx && nx<r && 0<=ny && ny<c) {
                        b[nx][ny] = 1;
                    }
                }
            }
        }
    }
    if (n == 1) {
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
       
    } else if (n % 2 == 0) {
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << 'O';
            }
            cout << '\n';
        }
    } else {
        // 몫이 홀수 일 때 a
        if (n%4 == 3) {
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    if (a[i][j] == 1)
                        cout << '.';
                    else
                        cout << 'O';
                }
            cout << '\n';
            }
        } else if (n%4 == 1){
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    if (b[i][j] == 1)
                        cout << '.';
                    else
                        cout << 'O';
                }
            cout << '\n';
            }
        }
    }

    return 0;
}