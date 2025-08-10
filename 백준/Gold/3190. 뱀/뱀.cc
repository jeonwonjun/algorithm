#include <iostream>
#include <queue>
using namespace std;

int N, K, L, X;
char C;
queue<pair<int, char>> v;
int dx[4] = {0, 1, 0, -1}; // 행 우하좌상
int dy[4] = {1, 0, -1, 0}; // 열 우하좌상
int board[101][101];
int sec, idx = 0;

// 종료조건
bool done(int x, int y)
{
    // board를 벗어날 때
    if (x < 1 || x > N || y < 1 || y > N) {
        sec++;
        return false;
    }
    // 몸통에 닿을 때는 board의 값이 1일 때로 대체
    else if (board[x][y] == 1) {
        sec++;
        return false;
    }

    return true;
}

int direction(int i)
{
    char vec = v.front().second;
    if (vec == 'L')
    { // 왼쪽
        if (i == 0)
            i = 3;
        else
            i--;
    }
    else if (vec == 'D')
    { // 오른쪽
        if (i == 3)
            i = 0;
        else
            i++;
    }

    return i;
}

void Dummy(int x, int y)
{
    // deque
    deque<pair<int, int>> body;
    body.push_front({x, y});
    board[x][y] = 1;

    int nx = x + dx[idx];
    int ny = y + dy[idx];

    while (done(nx, ny))
    {
        sec++;
        // 몸통 이동
        if (board[nx][ny] == 0)
        {
            int tailX = body.back().first;
            int tailY = body.back().second;
            body.push_front({nx, ny});
            board[nx][ny] = 1;
            board[tailX][tailY] = 0;
            body.pop_back();
        }
        else if (board[nx][ny] == 2) // 사과를 먹었을 때
        {
            body.push_front({nx, ny});
            board[nx][ny] = 1;
        }
        
        // 방향 정하기
        int cnt = v.front().first;
        if (cnt == sec)
        {
            idx = direction(idx);
            v.pop();
        }

        // 변한 방향으로 이동
        nx = nx + dx[idx];
        ny = ny + dy[idx];
    }
}

int main()
{
    cin >> N;
    cin >> K;
    // 사과 위치 넣기
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }
    // 방향 변화 시간 넣기
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> X >> C;
        v.push({X, C});
    }

    Dummy(1, 1);
    cout << sec<< '\n';
    return 0;
}