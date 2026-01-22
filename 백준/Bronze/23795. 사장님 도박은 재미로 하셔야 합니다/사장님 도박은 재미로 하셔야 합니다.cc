#include <iostream>
using namespace std;

int main() {
    int a;
    int sum = 0;
    
    cin >> a;
    while (a != -1) {
        sum += a;
        cin >> a;
    }
    
    cout << sum;
    return 0;
}