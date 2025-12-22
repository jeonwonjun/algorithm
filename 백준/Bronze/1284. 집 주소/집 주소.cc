#include <iostream>
using namespace std;

int main() {
    string number;
    while (cin >> number) {
        if (number == "0")
            break;
        int answer = 1;
        for (char c : number) {
            if (c == '1') {
                answer += 2;
            } else if (c == '0') {
                answer += 4;
            } else {
                answer += 3;
            }
            answer++;
        }
        cout << answer << '\n';
    }
    return 0;
}