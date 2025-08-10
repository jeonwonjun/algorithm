#include <iostream>
using namespace std;

int ans1 = 1;
int ans2 = 0;

int f[41];

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        ans1++;
        return fib(n-1) + fib(n-2);
    }
}

void fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i=3; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
        ans2++;
    }
}

int main() {
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    
    cout << ans1 << " " << ans2 << '\n';
    return 0;
}