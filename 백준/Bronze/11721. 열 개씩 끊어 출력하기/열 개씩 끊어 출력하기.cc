#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int i = 0;
    for (char c : str) {
        cout << c;
        i++;
        if (i == 10) {
            cout << '\n';
            i = 0;
        }
    }
    return 0;
}