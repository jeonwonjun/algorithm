#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        int h = h1 + h2;
        int m = m1 + m2;
        if (m >= 60) {
            h += m / 60;
            m %= 60;
        }

        if (h > 12) {
            h -= 12;
        }
        cout << "#" << i << ' ' << h << ' ' << m << '\n';
    }
    return 0;
}