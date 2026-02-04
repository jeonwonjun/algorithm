#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    
    int answer = INT_MAX;
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int total = a + b + (c*p);
        answer = min(answer, total);
    }
    
    cout << answer;
    return 0;
}