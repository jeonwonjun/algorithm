#include<iostream>
#include<cstring>

using namespace std;

int board[100][100];
int dx[3] = {0, 0, 1}; // 좌, 우, 하
int dy[3] = {-1, 1, 0};

int min_depth = 10001;
int answer = 0;
bool visited[100][100];
bool found = false;

void dfs(int x, int y, int depth, int start_y) {
    if (found) return;
    visited[x][y] = true;
    if (x == 99) {
        if (min_depth >= depth) {
            min_depth = depth;
            answer = start_y;
        }
        found = true;
        return ;
    }
    
    for (int dir = 0; dir < 3; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100) {
        	if (board[nx][ny] == 1 && !visited[nx][ny]) {
            	dfs(nx, ny, depth + 1, start_y);
        	}
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        cin>>T;
        min_depth = 10001;
        answer = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
            }
        }
        
        for (int i=0; i<100; i++) {
            if (board[0][i] == 0) continue;
            found = false;
            memset(visited, false, sizeof(visited));
            
            dfs(0, i, 1, i);
        }
        
        cout << "#" << T << " " << answer << '\n';
	}
	return 0;
}