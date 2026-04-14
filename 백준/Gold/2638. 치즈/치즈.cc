#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int board[102][102];
bool visited[102][102];

void findOutSide(int sx, int sy) {
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
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (!visited[nx][ny] && (board[nx][ny] == 0 || board[nx][ny] == -1)) {
                visited[nx][ny] = true;
                board[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    queue<pair<int, int>> cheese;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                cheese.push({i, j});
            }
        }
    }
    findOutSide(0, 0);
    int index = cheese.size();
    vector<pair<int, int>> v;
    int hours = 0;
    while (true) {
        index = cheese.size();
        if (cheese.empty()) {
            break;
        }
        while (index--) {
            int x = cheese.front().first;
            int y = cheese.front().second;
            cheese.pop();
            int count = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (board[nx][ny] == -1) {
                    count++;
                }
            }
            if (count >= 2) {
                v.push_back({x, y});
            } else {
                cheese.push({x, y});
            }
        }
        while (!v.empty()) {
            pair<int, int> last = v.back();
            board[last.first][last.second] = 0;
            v.pop_back();
        }
        memset(visited, false, sizeof(visited));
        findOutSide(0, 0);
        hours++;
    }
    cout << hours;
    return 0;
}