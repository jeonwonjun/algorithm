#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[5][5];
char map[5][5];
int cnt_min = 26;
using namespace std;


void dfs(int sx, int sy, int x, int y, int cnt)  {
    if (cnt > 2) return;
    if (!(sx == x && sy == y) && map[x][y] == 'P') {
        cnt_min = min(cnt, cnt_min);
        return ;
    } 
    
    for (int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
            if (map[nx][ny] != 'X' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(sx, sy, nx, ny, cnt + 1);
                visited[nx][ny] = false;
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int k=0; k<5; k++) 
    {
        vector<pair<int, int>> human;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                map[i][j] = places[k][i][j];
                if (map[i][j] == 'P'){
                    human.push_back({i, j});
                }
            }
        }
        
        for (int t=0; t<human.size(); t++) {
            auto[x, y] = human[t];
            visited[x][y] = true;
            dfs(x, y, x, y, 0);
            visited[x][y] = false;
        }
        if (cnt_min > 2)
            answer.push_back(1);
        else
            answer.push_back(0);
        
        memset(visited, false, sizeof(visited));
        cnt_min = 26;
    }
    
    return answer;
}