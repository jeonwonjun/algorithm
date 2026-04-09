#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long i = 1;
    int cnt = 0;
    while (n != 0) {
        if (n - i > i) {
            n -= i;
            i++;
            cnt++;
        } else {
            cnt++;
            break;
        }
    }
    
    cout << cnt;
    return 0;
}