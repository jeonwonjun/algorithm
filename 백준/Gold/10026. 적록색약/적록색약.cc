#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

// 색이 같은지 판단하는 함수
bool isSameColor(char a, char b, bool colorBlind) {
    if (colorBlind) {
        if ((a == 'R' || a == 'G') && (b == 'R' || b == 'G'))
            return true;
    }
    return a == b;
}

// 일반/색약 공통 bfs
void bfs(int sx, int sy, bool colorBlind) {
    visited[sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (!visited[nx][ny] && isSameColor(map[x][y], map[nx][ny], colorBlind)) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int countRegions(bool colorBlind) {
    memset(visited, false, sizeof(visited));
    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited[i][j]) {
                bfs(i, j, colorBlind);
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> map[i];
    }

    int normal = countRegions(false);
    int blind = countRegions(true);
    cout << normal << ' ' << blind << '\n';

    return 0;
}
