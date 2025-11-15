#include <iostream>
using namespace std;
char board[100][100];
int answer = 0;

bool checkPalidromY(int x, int y, int len) {
     
    for (int i = 0; i < len/2; i++) {
        if (board[x][y+i] != board[x][y + len-1 - i]) {
            return false;
        }
    }
     
    return true;
}
 
bool checkPalidromX(int x, int y, int len) {
     
    for (int i = 0; i < len/2; i++) {
        if (board[x+i][y] != board[x + len-1 - i][y]) {
            return false;
        }
    }
     
    return true;
}

void find_answer(int x, int y) {
    for (int i = 1; i <= 100 - x; i++) {
        if (checkPalidromX(x, y, i)) {
            answer = max(answer, i);
        }
    }
    for (int j = 1; j <= 100 - y; j++) {
        if (checkPalidromY(x, y, j)) {
            answer = max(answer, j);
        }
    }
}

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int T;
        cin >> T;
        
        answer = 0;
        // 1. board초기화
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
            }
        }
        
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                find_answer(i, j);
            }
        }
        cout << "#" << T << " " << answer << '\n';
    }
    
    return 0;
}