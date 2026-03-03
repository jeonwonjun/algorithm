#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if (n == 0)
            break;
        int answer = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                answer += i*j;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}