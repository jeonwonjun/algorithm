#include <iostream>
using namespace std;

int n, m;
int map[510][510];
int visited[510][510];
int dx[4] = {-1, 1, 0, 0}; // 상하좌우
int dy[4] = {0, 0, -1, 1};
int ans = 0;

void tetromino(int x, int y, int idx, int sum)
{
    if (idx == 4)
    {
        if (ans < sum)
            ans = sum;
        return;
    }

    // 4칸 이동할 수 있는 모든 경로 탐색
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                tetromino(nx, ny, idx + 1, sum + map[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // 모든 시작점부터 dfs 탐색, 보라색 제외
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            tetromino(i, j, 1, map[i][j]);
            visited[i][j] = false;
        }
    }

    // 보라색 테트로미노 구하기
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int t = map[i][j]; // 보라색 테트로미노의 가운데
            int purple_min = 1001;
            int cnt = 0;
            for (int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    purple_min = min(purple_min, map[nx][ny]);
                    t += map[nx][ny];
                    cnt ++;
                }
            }

            // 범위값을 벗어나서 ㄱ, ㄴ 등 보라색 모양이 안나올 수 있음.
            // 모든 칸을 검사하더라도 3칸의 크기가 더 큰 경우가 있기 때문에
            // 예외처리를 꼭 해줘야함.
            if (cnt == 4) {
                ans = max(ans, t - purple_min);
            } else if (cnt == 3) {
                ans = max(ans, t);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}