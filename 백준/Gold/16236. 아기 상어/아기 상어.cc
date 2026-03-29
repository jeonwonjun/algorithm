#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, baby_shark = 2, amount = 0;
int answer = 1;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int sea[20][20];
int next_X, next_Y;

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    int dist[20][20] = {0, };
    dist[sx][sy] = 0;
    q.push({sx, sy});

    int min_dist = 21483647;
    vector<pair<int, int>> fish;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != 0 || (nx == sx && ny == sy)) continue;
            if (sea[nx][ny] > baby_shark) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;

            if (sea[nx][ny] != 0 && sea[nx][ny] < baby_shark) {
                if (dist[nx][ny] < min_dist) {
                    min_dist = dist[nx][ny];
                    fish.clear();
                    fish.push_back({nx, ny});
                } else if (dist[nx][ny] == min_dist) {
                    fish.push_back({nx, ny});
                }                
            }
        }
    }

    if (fish.empty()) {
        return 0;
    }
    
    sort(fish.begin(), fish.end());
    next_X = fish[0].first;
    next_Y = fish[0].second;
    
    sea[next_X][next_Y] = 0;
    amount++;

    return min_dist;
}

int main() {
    queue<pair<int, int>> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                next_X = i;
                next_Y = j;
                sea[i][j] = 0;
            }
        }
    }

    q.push({next_X, next_Y});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int d = bfs(x, y);
        if (d == 0) {
            break;
        }
        q.push({next_X, next_Y});
        answer += d;
        if (amount == baby_shark) {
            baby_shark++;
            amount = 0;
        }
    }

    cout << answer - 1;
    return 0;
}