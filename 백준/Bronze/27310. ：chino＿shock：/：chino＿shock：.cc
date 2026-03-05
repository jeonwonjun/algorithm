#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int underBarCount = 0;
    int cloneCount = 0;
    for (char c : str) {
        if (c == ':')
            cloneCount++;
        else if (c == '_')
            underBarCount++;
    }
    cout << str.length() + cloneCount + underBarCount*5;
    return 0;
}