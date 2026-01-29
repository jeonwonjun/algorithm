#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;
    for (int i = 0; i < n; i++) {
        int cute;
        cin >> cute;
        if (cute) answer++;
    }

    if (answer > (n / 2))
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";
    return 0;
}