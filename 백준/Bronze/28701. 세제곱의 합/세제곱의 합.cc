#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int answer1 = 0;
    for (int i=1; i<=n; i++) {
        answer1 += i;
    }

    cout << answer1 << '\n';

    cout << answer1*answer1 << '\n';

    int answer3 = 0;
    for (int i=1; i<=n; i++) {
        answer3 += pow(i, 3);
    }

    cout << answer3;
    return 0;
}