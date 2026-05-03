#include <iostream>
using namespace std;

const long long MOD = 998244353;
const long long INV2 = 499122177;

long long sumToN(long long n) {
    n %= MOD;
    return n * ((n + 1) % MOD) % MOD * INV2 % MOD;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long answer = 1;
        answer = answer * sumToN(a) % MOD;
        answer = answer * sumToN(b) % MOD;
        answer = answer * sumToN(c) % MOD;

        cout << answer << '\n';
    }
    
    return 0;
}