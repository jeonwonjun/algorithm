#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int glacier[301][301];
bool visited[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void melt() {
    int temp[301][301];
    memcpy(temp, glacier, sizeof(glacier));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (glacier[i][j] > 0) {
                int sea = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && glacier[nx][ny] == 0) {
                        sea++;
                    }
                }
                temp[i][j] = max(0, glacier[i][j] - sea);
            }
        }
    }
    memcpy(glacier, temp, sizeof(temp));
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (glacier[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> glacier[i][j];
        }
    }

    int year = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (glacier[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    count++;
                }
            }
        }

        if (count >= 2) {
            cout << year << endl;
            return 0;
        }
        if (count == 0) {
            cout << 0 << endl;
            return 0;
        }

        melt();
        year++;
    }

    return 0;
}