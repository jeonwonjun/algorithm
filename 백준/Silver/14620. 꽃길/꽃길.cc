#include <iostream>
using namespace std;

int map[10][10];
bool visited[10][10];
int N;
int ans = 50000;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 씨앗 하나당 가격 구하기
int seed(int x, int y)
{
    visited[x][y] = true;
    int sum = map[x][y];
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        visited[nx][ny] = true;
        sum += map[nx][ny];
    }
    return sum;
}

// 방문해제
void unseed(int x, int y)
{
    visited[x][y] = false;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        visited[nx][ny] = false;
    }
}

bool check(int x, int y)
{
    if (visited[x][y]) return false;

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
        if (visited[nx][ny]) return false;
    }

    return true;
}

void getCost(int idx, int cost)
{
    if (idx == 3)
    {
        ans = min(ans, cost);
        return;
    }

    for (int i = 1; i < N - 1; i++) // 가장자리는 검사 안 해도 됨
    {
        for (int j = 1; j < N - 1; j++)
        {
            if (check(i, j))
            {
                int tmp = seed(i, j);
                getCost(idx + 1, cost + tmp);
                unseed(i, j);
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    getCost(0, 0);

    cout << ans << '\n';
    return 0;
}
