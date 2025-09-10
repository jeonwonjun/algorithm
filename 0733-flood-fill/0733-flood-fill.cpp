class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int d[50][50];
    bool visited[50][50];
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // bfs
        vector<vector<int>> d = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int c = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        d[sr][sc] = color;
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    if(d[nx][ny] == c && !visited[nx][ny]) {
                        d[nx][ny] = color;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return d;
    }
};