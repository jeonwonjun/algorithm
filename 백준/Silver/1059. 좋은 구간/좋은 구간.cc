#include <iostream>
#include <algorithm>
using namespace std;

int L, n;
int S[51];

int main() {
    cin >> L;
    for (int i=0; i<L; i++) {
        cin >> S[i];
    }
    
    sort(S, S+L);

    cin >> n;
    
    int idx, ans;
    for (int i=0; i<L; i++) {
        if (S[i] == n) {
            cout << 0 << '\n';
            return 0;
        }
        if (S[i] >= n)  {
            idx = i;
            break;
        }
    }
    
    ans = (S[idx]-n)*(n-S[idx-1]) - 1;
    cout << ans << '\n';
    
    return 0;
}