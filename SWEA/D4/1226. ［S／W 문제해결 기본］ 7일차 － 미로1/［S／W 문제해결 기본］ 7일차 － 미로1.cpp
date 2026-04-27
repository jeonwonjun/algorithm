#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs() {
    vector<string> board(16);
    vector<vector<bool>> visited(16, vector<bool>(16, false));
    for (int i = 0; i < 16; i++) {
        getline(cin, board[i]);
    }

    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (board[i][j] == '2') {
                sx = i;
                sy = j;
            } else if (board[i][j] == '3') {
                ex = i;
                ey = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
            if (board[nx][ny] != '1' && visited[nx][ny] == false) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    if (visited[ex][ey]) {
        return 1;
    }

    return 0;
}

int main() {

    for (int test_case = 1; test_case <= 10; test_case++) {
        int t;
        cin >> t;
        cin.ignore();
        int answer = bfs();
        cout << "#" << test_case << " " << answer << '\n';
    }
    
    return 0;
}