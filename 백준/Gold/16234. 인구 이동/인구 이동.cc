#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, L, R;
int board[51][51];
bool visited[51][51];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y, vector<pair<int,int>>& unionCells) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    unionCells.push_back({x, y});
    int sum = board[x][y];

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;

            int diff = abs(board[cx][cy] - board[nx][ny]);

            if (diff >= L && diff <= R) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                unionCells.push_back({nx, ny});
                sum += board[nx][ny];
            }
        }
    }

    return sum;
}

int main() {
    cin >> n >> L >> R;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int days = 0;

    while (true) {
        bool moved = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    vector<pair<int,int>> unionCells;

                    int sum = bfs(i, j, unionCells);

                    if (unionCells.size() > 1) {
                        moved = true;
                        int avg = sum / unionCells.size();

                        for (auto &p : unionCells) {
                            board[p.first][p.second] = avg;
                        }
                    }
                }
            }
        }

        if (!moved) break;

        days++;
    }

    cout << days << '\n';
    return 0;
}