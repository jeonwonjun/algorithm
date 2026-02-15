#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;
    
    for (int i=0; i<n.length()/2; i++) {
        cout << n[i];
    }
    cout << ' ';
    
    for (int i=(n.length()/2); i<n.length(); i++) {
        cout << n[i];
    }
    return 0;
}