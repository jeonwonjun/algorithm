#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> board;
    for (int i = 0; i < n; i++) {
        int sheep;
        cin >> sheep;

        board.push_back(sheep);
    }

    sort(board.rbegin(), board.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (board[i] >= i + 1) {
            ans += board[i] - i;
        } else {
            break;
        }
    }

    cout << ans;
    return 0;
}