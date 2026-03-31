#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool used[10];
vector<char> inequality_sign;
vector<char> answer;
bool flag = false;

bool isPossible(int depth) {
    if (depth == 0) {
        return true;
    }

    if (inequality_sign[depth - 1] == '<') {
        return answer[depth - 1] < answer[depth];
    } else if (inequality_sign[depth - 1] == '>') {
        return answer[depth - 1] > answer[depth];
    }
    
    return false;
}

void maxDfs(int depth) {
    if (depth == n + 1) {
        flag = true;
        return ;
    }
    
    for (int i = 9; i >= 0; i--) {
        if (!used[i]) {
            used[i] = true;
            answer.push_back(num[i]);
            if (isPossible(depth)) {
                maxDfs(depth + 1);
            }
            if (flag) {
                break;
            }
            answer.pop_back();
            used[i] = false;
        }
    }
}

void minDfs(int depth) {
    if (depth == n + 1) {
        flag = true;
        return ;
    }
    
    for (int i = 0; i < 10; i++) {
        if (!used[i]) {
            used[i] = true;
            answer.push_back(num[i]);
            if (isPossible(depth)) {
                minDfs(depth + 1);
            }
            if (flag) {
                break;
            }
            used[i] = false;
            answer.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char sign;
        cin >> sign;
        inequality_sign.push_back(sign);
    }

    maxDfs(0);

    for (char c : answer) {
        cout << c;
    }    

    cout << '\n';
    answer.clear();
    memset(used, 0, sizeof(used));
    flag = false;
    
    minDfs(0);

    for (char c : answer) {
        cout << c;
    }    
    return 0;
}