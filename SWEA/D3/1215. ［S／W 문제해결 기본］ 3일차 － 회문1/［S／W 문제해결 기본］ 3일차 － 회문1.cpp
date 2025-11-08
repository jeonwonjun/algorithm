#include<iostream>
using namespace std;
char board[8][8];

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


int main() {
    for (int test_case = 1; test_case <= 10; test_case++) {
        int answer = 0;
        int len;
        cin >> len;
        for (int i = 0; i < 8; i++) {
            cin >> board[i];
        }
        
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - len; j++) {
                if (checkPalidromY(i, j, len)) answer++;
            }
        }
        for (int i = 0; i <= 8 - len; i++) {
            for (int j = 0; j < 8; j++) {

                if (checkPalidromX(i, j, len)) answer++;
            }
        }
        
        
        cout << "#" << test_case << " " << answer << '\n';
    }
    return 0;
}