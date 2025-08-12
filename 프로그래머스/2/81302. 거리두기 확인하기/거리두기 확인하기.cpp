#include <vector>
#include <string>
#include <cstring>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char board[5][5];
bool visited[5][5];
bool safe;

void dfs(int sx, int sy, int x, int y, int dist) {
    if (dist > 2 || !safe) return; // 거리 제한 or 이미 위반 발견
    if (!(sx == x && sy == y) && board[x][y] == 'P') {
        safe = false; // 거리두기 위반
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (!visited[nx][ny] && board[nx][ny] != 'X') {
            visited[nx][ny] = true;
            dfs(sx, sy, nx, ny, dist + 1);
            visited[nx][ny] = false;
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int t = 0; t < 5; t++) {
        // 보드 세팅
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                board[i][j] = places[t][i][j];

        safe = true;
        for (int i = 0; i < 5 && safe; i++) {
            for (int j = 0; j < 5 && safe; j++) {
                if (board[i][j] == 'P') {
                    memset(visited, false, sizeof(visited));
                    visited[i][j] = true;
                    dfs(i, j, i, j, 0);
                }
            }
        }
        answer.push_back(safe ? 1 : 0);
    }
    return answer;
}
