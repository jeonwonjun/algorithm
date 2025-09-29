#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int d[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int sx, int sy, int cnt, vector<vector<int>> &land){
    // 인접한 석유 계산
    queue<pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = cnt;
    int oil_size = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= land.size() || ny < 0 || ny >= land[0].size()) continue;
            if (land[nx][ny] == 1 && !d[nx][ny]){
                q.push({nx, ny});
                d[nx][ny] = cnt;
                oil_size++;
            }
        }
    }
    
    return oil_size;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    unordered_map<int, int> m; // 오일 크기 저장
    int cnt = 0;
    for(int i=0; i<land.size(); i++){
       for (int j=0; j<land[i].size(); j++){
            // hash table에 석유 크기 저장
           if (land[i][j] == 1 && !d[i][j])
                m[cnt] = bfs(i, j, ++cnt, land);
       } 
    }
    
    for(int i=0; i<land[0].size(); i++){
        unordered_map<int, int> m2; // 시추관을 지나가는 개수
        int sum = 0;
        for(int j=0; j<land.size(); j++){
           if (d[j][i] > 0 && m2[d[j][i]] < 1){
                m2[d[j][i]]++;
               sum += m[d[j][i]];
           }
        }
        answer = max(answer, sum);
         
    }
    
    return answer;
}