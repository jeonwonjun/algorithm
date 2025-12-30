#include <iostream>
#include <queue>
using namespace std;

char board[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int r,c;

void bfs(int sx, int sy, int cnt) {
  
  queue<pair<int, int>> q;
  q.push({sx, sy});
  visited[sx][sy] = true;
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int dir=0; dir<4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (0 > nx || nx >= r || 0 > ny || ny >= c) continue;
      if (board[nx][ny] == '#' && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}

int main() 
{

    cin >> r >> c;

    for (int i=0; i<r; i++) {
      cin >> board[i];
    }
    
    int cnt = 0;
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
        if (board[i][j] == '#' && !visited[i][j]) {
          bfs(i, j, ++cnt);
        }
      }
    }
    
    cout << cnt;
    
    return 0;
}