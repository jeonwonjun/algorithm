#include <iostream>
using namespace std;

int board[5][5];
bool marked[5][5];
pair<int, int> numPos[26]; // 숫자 위치 저장

int countBingo() {
    int bingo = 0;

    // 가로
    for (int i = 0; i < 5; i++) {
        bool row = true;
        for (int j = 0; j < 5; j++) {
            if (!marked[i][j]) row = false;
        }
        if (row) bingo++;
    }

    // 세로
    for (int j = 0; j < 5; j++) {
        bool col = true;
        for (int i = 0; i < 5; i++) {
            if (!marked[i][j]) col = false;
        }
        if (col) bingo++;
    }

    // 대각선 ↘
    bool diag1 = true;
    for (int i = 0; i < 5; i++) {
        if (!marked[i][i]) diag1 = false;
    }
    if (diag1) bingo++;

    // 대각선 ↙
    bool diag2 = true;
    for (int i = 0; i < 5; i++) {
        if (!marked[i][4 - i]) diag2 = false;
    }
    if (diag2) bingo++;

    return bingo;
}

int main() {
    // 내 빙고판 저장 + 숫자 위치 기억
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
            numPos[num] = {i, j};
        }
    }

    // 사회자가 부르는 숫자 25개
    int count = 0;
    for (int i = 0; i < 25; i++) {
        int called;
        cin >> called;
        count++;

        // 해당 숫자 체크
        auto [x, y] = numPos[called];
        marked[x][y] = true;

        // 빙고 개수 확인
        if (count >= 12) { // 3줄 이상 가능해지는 최소 시점
            int bingo = countBingo();
            if (bingo >= 3) {
                cout << count << '\n';
                break;
            }
        }
    }

    return 0;
}