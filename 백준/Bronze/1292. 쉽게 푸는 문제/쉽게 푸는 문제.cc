#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int i1 = 1;
    int k1=1;
    int cnt1 = 1;
    int sum1 = 0;
    while (cnt1 <= b) {
        int j=1;
        while (j <= k1 && cnt1 <= b) {
            sum1 += i1;
            cnt1++;
            j++;
        }
        i1++;
        k1++;
    }
    
    int i2=1;
    int k2=1;
    int cnt2 = 1;
    int sum2 = 0;
    while (cnt2 < a) {
        int j=1;
        while (j<=k2 && cnt2 < a) {
            sum2 += i2;
            j++;
            cnt2++;
        }
        i2++;
        k2++;
    }
    
    cout << sum1 - sum2;
}