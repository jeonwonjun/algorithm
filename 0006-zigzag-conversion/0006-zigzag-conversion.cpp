class Solution {
public:
    // dx, dy 방향 설정: [0]은 아래로 내려가기, [1]은 오른쪽 위 대각선으로 올라가기
    int dx[2] = {1, -1};
    int dy[2] = {0, 1};

    string convert(string s, int numRows) {
        // 예외 처리: 행이 1개이거나 문자열이 행보다 짧으면 변환이 필요 없음
        if (numRows == 1 || s.length() <= numRows) return s;

        string res = "";
        int len = s.length();
        
        vector<vector<char>> v(numRows, vector<char>(len, ' '));
        
        int i = 0;
        int x = 0, y = 0; // x, y 좌표는 while 루프 밖에서 유지되어야 합니다.

        while (i < len) {
            for (int j = 0; j < numRows - 1 && i < len; j++) {
                v[x][y] = s[i++];
                x += dx[0];
                y += dy[0];
            }

            for (int j = 0; j < numRows - 1 && i < len; j++) {
                v[x][y] = s[i++];
                x += dx[1];
                y += dy[1];
            }
        }

        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < len; c++) {
                if (v[r][c] != ' ') {
                    res += v[r][c];
                }
            }
        }
        return res;
    }
};