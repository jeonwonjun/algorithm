#include <iostream>
using namespace std;

int prefixSum(int n) {
    int num = 1;
    int cnt = 0;
    int sum = 0;

    while (cnt < n) {
        for (int i = 0; i < num && cnt < n; i++) {
            sum += num;
            cnt++;
        }
        num++;
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << prefixSum(b) - prefixSum(a - 1);
}
