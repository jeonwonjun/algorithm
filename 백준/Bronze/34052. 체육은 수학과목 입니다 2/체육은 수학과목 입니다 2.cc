#include <iostream>
using namespace std;

int main() {
    
    int sum = 0;
    for (int i=0; i<4; i++) {
        int num;
        cin >> num;
        sum += num;
    }
    
    sum += 300;
    if (sum <= 1800) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}