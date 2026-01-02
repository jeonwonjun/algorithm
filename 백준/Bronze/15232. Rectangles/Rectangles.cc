#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int r, c;
    cin >> r;
    cin >> c;
    
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout <<'*';
        }
        cout << '\n';
    }
}