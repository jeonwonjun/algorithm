#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    string num1 = to_string(a) + to_string(b);
    string num2 = to_string(c) + to_string(d);

    cout << stol(num1) + stol(num2);
    
    return 0;
}