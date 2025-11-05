#include<iostream>
#include<cstring>

using namespace std;

const int N = 100;
int board[N][N];
bool visited[N][N];
int answerY = -1;
bool found = false;

// 방향: 왼쪽, 오른쪽, 위쪽 (dx, dy)
int dx[3] = {0, 0, -1};
int dy[3] = {-1, 1, 0};

bool inRange(int x, int y) {
    return (x < N && 0 <= y && y < N);
}

void dfs(int x, int y) {
    visited[x][y] = true;

    if (x == 0) {
        answerY = y;
        found = true;
        return;
    }
    
    for (int dir = 0; dir < 3; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (inRange(nx, ny) && !visited[nx][ny] && board[nx][ny] == 1) {
            dfs(nx, ny);
            if (found) return;
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        found = false;
        answerY = -1;
        int n;
        cin >> n;
        for (int i = 0; i < N; ++i) {
        	for (int j = 0; j < N; ++j) {
            	cin >> board[i][j];
        	}
    	}
        memset(visited, 0, sizeof(visited));

    	int sx = N - 1;
    	int sy = -1;
    	for (int j = 0; j < N; ++j) {
        	if (board[sx][j] == 2) {
            	sy = j;
            	break;
        	}
    	}
    
    	dfs(sx, sy);

    	cout << "#" << test_case << " " << answerY << "\n";

		}
	return 0;
}