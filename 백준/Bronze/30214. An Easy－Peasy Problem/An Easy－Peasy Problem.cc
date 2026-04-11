#include <iostream>
using namespace std;

int main() {
    int s1, s2;
    cin >> s1 >> s2;
    
    if (s2 % 2 > 0) {
        if (s1 > s2/2) {
            cout << "E";
        } else {
            cout << "H";   
        }
    } else {
        if (s1 >= s2/2) {
            cout << "E";
        } else {
            cout << "H";   
        }
    }
    return 0;
}