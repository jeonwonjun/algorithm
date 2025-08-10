#include <iostream>
using namespace std;
#define MAX 1000001

int D[MAX];
int N;

int main() {

    cin >> N;
    D[0] = 1;
    D[1] = 1;
    for (int i=2; i<=N; i++) {
        D[i] = (D[i-2] + D[i-1]) % 15746;
    }

    cout << D[N] << '\n';
    return 0;
}