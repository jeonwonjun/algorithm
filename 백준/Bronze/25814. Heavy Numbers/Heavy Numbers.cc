#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int answer1 = a.length();
    int sum1 = 0;

    for (char c : a) {
        sum1 += c - '0';
    }
    answer1 = answer1*sum1;
    
    int answer2 = b.length();
    int sum2 = 0;
    for (char c : b) {
        sum2 += c - '0';
    }
    answer2 = answer2*sum2;
    
    if (answer1 == answer2)
        cout << 0;
    else if (answer1 > answer2)
        cout << 1;
    else
        cout << 2;
    return 0;
}