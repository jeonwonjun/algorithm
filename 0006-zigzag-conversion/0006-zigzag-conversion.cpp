class Solution {
public:
    int dx[2] = {1, -1};
    int dy[2] = {0, 1};

    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        string res = "";
        int len = s.length();
        
        vector<vector<char>> v(numRows, vector<char>(len, ' '));
        
        int i = 0;
        int x = 0, y = 0;

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