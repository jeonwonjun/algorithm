#include <iostream>
using namespace std;
int coin[6] = {500, 100, 50, 10, 5, 1};

int main() {
    int fee;
    cin >> fee;
    int extra_fee = 1000 - fee;
    int answer = 0;
    int i = 0;
    while (true) {
        if (extra_fee == 0) break;

        answer += extra_fee / coin[i];
        extra_fee %= coin[i];
        i++;
    }

    cout << answer;
    return 0;
}