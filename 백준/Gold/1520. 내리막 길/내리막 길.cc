#include <iostream>
#include <cstring>
using namespace std;

int m, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int map[500][500];
int dp[500][500];

int dfs(int x, int y) {
    if (x == m-1 && y == n-1) return 1; // 목적지 도착
    if (dp[x][y] != -1) return dp[x][y]; // 이미 탐색했다면 돌아가기

    dp[x][y] = 0;
    for (int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (map[nx][ny] < map[x][y]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    cin >> m >> n;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    int ans = dfs(0, 0);

    cout << ans << '\n';

    return 0;
}