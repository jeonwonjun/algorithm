#include <iostream>
using namespace std;

int main() {
    int n, k;
    int sum = 0;
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        sum += i;
    }
    
    if (n < sum) {
        cout << -1 << '\n';
    } else {
        if ((n - sum)%k == 0) {
            cout << k - 1 << '\n';
        } else
            cout << k << '\n';
    }
    return 0;
}