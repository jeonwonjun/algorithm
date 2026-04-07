#include <iostream>
#include <cmath>
using namespace std;

int cnt;

void hanoi(int cnt, int start, int sub, int end) {
    if (cnt == 1) {
        cout << start << ' ' << end << '\n';
        return ;
    }

    hanoi(cnt - 1, start, end, sub);
    cout << start << ' ' << end << '\n';
    hanoi(cnt - 1, sub, start, end);
}

int main() {
    cin >> cnt;
    cout << (int) pow(2, cnt) - 1 << '\n';
    hanoi(cnt, 1, 2, 3);
    return 0;
}