#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int dx[4];
int dy[4];
int d[100][100]; // 영역개수 및 방문 현황 저장
int board[100][100];

void bfs(int sx, int sy, int m, int n, int cnt, int &max_size) {
    int cnt_area = 1;
    int color = board[sx][sy];
    queue<pair<int,int>> q;
    q.push({sx, sy});
    d[sx][sy] = cnt;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!d[nx][ny] && board[nx][ny] == color) {
                d[nx][ny] = cnt;
                cnt_area++;
                q.push({nx, ny});
            }
        }
    }
    max_size = max(max_size, cnt_area);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);

    dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
    dy[0] = 0; dy[1] = 0; dy[2] = -1; dy[3] = 1;
    memset(d, 0, sizeof(d));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = picture[i][j];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!d[i][j] && board[i][j] != 0) {
                bfs(i, j, m, n, ++number_of_area, max_size_of_one_area);
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}