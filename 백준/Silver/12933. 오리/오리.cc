#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[5] = {0};
    int max_duck = 0;

    for (char ch : s) {
        if (ch == 'q') {
            cnt[0]++;
        } 
        else if (ch == 'u') {
            if (cnt[0] == 0) {
                cout << -1;
                return 0;
            }
            cnt[0]--;
            cnt[1]++;
        }
        else if (ch == 'a') {
            if (cnt[1] == 0) {
                cout << -1;
                return 0;
            }
            cnt[1]--;
            cnt[2]++;
        }
        else if (ch == 'c') {
            if (cnt[2] == 0) {
                cout << -1;
                return 0;
            }
            cnt[2]--;
            cnt[3]++;
        }
        else if (ch == 'k') {
            if (cnt[3] == 0) {
                cout << -1;
                return 0;
            }
            cnt[3]--;
        }
        
        int current = cnt[0] + cnt[1] + cnt[2] + cnt[3];
        max_duck = max(max_duck, current);
    }

    if (cnt[0] || cnt[1] || cnt[2] || cnt[3]) {
        cout << -1;
    } else {
        cout << max_duck;
    }

    return 0;
}