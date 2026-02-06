#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int sum = 0;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    
    sum += 8*(n-1);
    
    cout << sum / 24 << ' ' << sum % 24;
    return 0;
}