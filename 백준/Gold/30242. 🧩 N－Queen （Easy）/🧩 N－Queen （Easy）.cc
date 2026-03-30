#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 21

bool col_used[MAX];
bool diag1[MAX * 2];
bool diag2[MAX * 2];

int n;
int col[MAX];
bool flag = false;

void dfs(int row) {
    if (row > n) {
        flag = true;
        for (int i = 1; i <= n; i++) {
            cout << col[i] << ' ';
        }
        return;
    }

    if (col[row] != 0) {
        dfs(row + 1);
        return;
    }

    for (int c = 1; c <= n; c++) {
        if (col_used[c] || diag1[row + c] || diag2[row - c + n]) continue;

        col[row] = c;
        col_used[c] = diag1[row + c] = diag2[row - c + n] = true;

        dfs(row + 1);

        if (flag) return;

        col_used[c] = diag1[row + c] = diag2[row - c + n] = false;
        col[row] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }

    for (int i = 1; i <= n; i++) {
        if (col[i] != 0) {
            int c = col[i];

            if (col_used[c] || diag1[i + c] || diag2[i - c + n]) {
                cout << -1;
                return 0;
            }

            col_used[c] = diag1[i + c] = diag2[i - c + n] = true;
        }
    }

    dfs(1);

    if (flag == false) {
        cout << -1;
    }
    
    return 0;
}