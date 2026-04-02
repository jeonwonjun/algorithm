#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int answer = 0;
    while (b > a) {
        if (b % 2 == 0) {
            b /= 2;
        } else {
            string str = to_string(b);
            if (str.length() < 2 || str.back() != '1') {
                cout << -1;
                return 0;
            } else {
                str.pop_back();
                b = stoi(str);
            }
        }
        answer++;
    }

    if (b < a) {
        cout << -1;
        return 0;
    }

    cout << answer + 1;
    return 0;
}