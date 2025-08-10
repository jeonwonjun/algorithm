#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h; // 가로, 세로, 높이
int box[100][100][100];
int dz[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {-1, 1, 0, 0, 0, 0};

int main() {
    queue<tuple<int, int, int>> q;
    cin >> m >> n >> h;

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1)
                    q.push({k, i, j}); // 익은 토마토는 큐에 미리 넣음
            }
        }
    }

    while (!q.empty()) {
        auto [z, x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dx[dir];
            int nx = x + dy[dir];
            int ny = y + dz[dir];
            if (0 <= nz && nz < h && 0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (box[nz][nx][ny] == 0) {
                    box[nz][nx][ny] = box[z][x][y] + 1; // 날짜 저장
                    q.push({nz, nx, ny});
                }
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (box[k][i][j] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                ans = max(ans, box[k][i][j]);
            }
        }
    }

    cout << ans - 1 << '\n'; // 초기값이 1이므로 하루를 빼줌
    return 0;
}
