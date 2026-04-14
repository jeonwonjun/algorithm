#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int board[102][102];
bool visited[102][102];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void resetAir() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0;
            }
        }
    }
}

void findOutside() {
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    board[0][0] = -1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (!visited[nx][ny] && board[nx][ny] == 0) {
                visited[nx][ny] = true;
                board[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
    }
}

bool meltCheese() {
    bool melted = false;
    int temp[102][102];
    memcpy(temp, board, sizeof(board));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                int cnt = 0;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (board[nx][ny] == -1) {
                        cnt++;
                    }
                }

                if (cnt >= 2) {
                    temp[i][j] = 0;
                    melted = true;
                }
            }
        }
    }

    memcpy(board, temp, sizeof(board));
    return melted;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int hours = 0;

    while (true) {
        resetAir();
        findOutside();
        if (!meltCheese()) break;
        hours++;
    }

    cout << hours;
    return 0;
}