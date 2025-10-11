#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int d[102][102];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    
    int x1, x2, y1, y2;
    // 1. 사각형 1로 채우기
    for(int i=0; i < rectangle.size(); i++){
        x1 = rectangle[i][0]*2, x2 = rectangle[i][2]*2;
        y1 = rectangle[i][1]*2, y2 = rectangle[i][3]*2;
        for(int x=x1; x<=x2; x++){
            for(int y=y1; y<=y2; y++){
                d[x][y] = 1;
            }
        }
    }
    
    // 2. 사각형 내부 0으로 채우기
    for(int i=0; i < rectangle.size(); i++){
        x1 = rectangle[i][0]*2, x2 = rectangle[i][2]*2;
        y1 = rectangle[i][1]*2, y2 = rectangle[i][3]*2;
        for(int x=x1+1; x<=x2-1; x++){
            for(int y=y1+1; y<=y2-1; y++){
                d[x][y] = 0;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        
        if(x == itemX && y == itemY)
            break;
        
        for(int dir = 0; dir<4; dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(d[nx][ny] == 1){
                q.push({nx, ny});
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }
    
    answer = d[itemX][itemY] / 2;
    return answer;
    
}