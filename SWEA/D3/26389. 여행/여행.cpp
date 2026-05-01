#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        unordered_map<char, int> dir;
        string direction;
        cin >> direction;
        
        for (char c : direction) {
            dir[c]++;
        }

        string answer = "Yes";
        if ((dir['N'] > 0 && dir['S'] == 0) || (dir['N'] == 0 && dir['S'] > 0)) {
            answer = "No";
        } else if ((dir['W'] > 0 && dir['E'] == 0) || (dir['W'] == 0 && dir['E'] > 0)) {
            answer = "No";
        }

        cout << answer << '\n';
    }
    return 0;
}