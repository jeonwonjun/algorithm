#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        if (x == 1) {
            cout << 0;
        } else if (x % 2 != 0) {
            cout << 4;
            for (int i = 0; i < x/2; i++) {
                cout << 8;
            }
        } else if (x % 2 == 0) {
            for (int i = 0; i < x/2; i++) {
                cout << 8;
            }
        }
        cout << '\n';
    }
    return 0;
}