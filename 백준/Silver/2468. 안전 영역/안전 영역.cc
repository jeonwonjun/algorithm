#include <iostream>
using namespace std;

int n;
int map[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int temp[100][100];

// 물높이와 같거나 낮은 것들은 temp값에 1 저장
void set_temp(int h)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] <= h)
                temp[i][j] = 1;
            else
                temp[i][j] = 0;
        }
    }
}

// 방문 영역 및 인접 영역은 -1 저장
void dfs(int sx, int sy, int cnt) {
    temp[sx][sy] = -1;
    for (int k=0; k<4; k++) {
        int nx = sx + dx[k];
        int ny = sy + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (temp[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}

// 안전 영역의 개수 구하기
int get_safezone()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }

    return cnt;
}

int main()
{

    cin >> n;
    int imax = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            imax = max(imax, map[i][j]);
        }
    }

    int ans = 0;
    // 비가 안올 수 있기 때문에 0부터 탐색
    for (int m = 0; m <= imax; m++)
    {
        set_temp(m);
        int s = get_safezone();
        ans = max(ans, s);
    }

    cout << ans << '\n';

    return 0;
}