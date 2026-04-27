#include <iostream>
using namespace std;

int cntCondition(string str) {
    int cnt = 0;
    for (char c : str) {
        if (c == '3' || c == '6' || c == '9') {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
        int cnt = cntCondition(str);
        if (cnt > 0) {
            while(cnt--) {
                cout << '-';
            }
        } else {
            cout << i;
        }
        cout << ' ';
    }
    return 0;
}