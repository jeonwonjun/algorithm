#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {  
        int a, b;
        cin >> a >> b;
        int c = 1;
        for (int i=0; i<b; i++) {
            c *= a;
            c %= 10;
        }
        if (c == 0) {
            cout << 10 << '\n';
        }
        else
            cout << c << '\n';
    }
}
