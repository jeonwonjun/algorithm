#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    
    int answer = 1;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == answer) {
            answer = b;
        } else if (b == answer) {
            answer = a;
        }
    }
    
    cout << answer;
}