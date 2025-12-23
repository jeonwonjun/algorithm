#include <iostream>
#include <vector>
using namespace std;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check_heart(int x, int y, vector<string>& cookie) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || cookie[nx][ny] == '_')
            return false;
    }
    return true;
}

int measure(int x, int y, int dx, int dy, vector<string>& cookie) {
    int cnt = 0;
    while (x >= 0 && x < n && y >= 0 && y < n && cookie[x][y] == '*') {
        cnt++;
        x += dx;
        y += dy;
    }
    return cnt;
}

int main() {
    cin >> n;
    vector<string> cookie(n);
    for (int i = 0; i < n; i++) {
        cin >> cookie[i];
    }

    // 심장 찾기
    int hx = 0, hy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cookie[i][j] == '*' && check_heart(i, j, cookie)) {
                hx = i;
                hy = j;
            }
        }
    }

    cout << hx + 1 << " " << hy + 1 << '\n';

    // 신체 길이 측정
    int left_arm = measure(hx, hy - 1, 0, -1, cookie);
    int right_arm = measure(hx, hy + 1, 0, 1, cookie);
    int waist = measure(hx + 1, hy, 1, 0, cookie);

    int waist_end = hx + waist;

    int left_leg = measure(waist_end + 1, hy - 1, 1, 0, cookie);
    int right_leg = measure(waist_end + 1, hy + 1, 1, 0, cookie);

    cout << left_arm << " "
         << right_arm << " "
         << waist << " "
         << left_leg << " "
         << right_leg << '\n';

    return 0;
}
