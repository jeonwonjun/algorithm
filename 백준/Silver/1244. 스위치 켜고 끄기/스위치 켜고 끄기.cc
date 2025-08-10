#include <iostream>
using namespace std;
int button[110];

int main() {

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> button[i];
    }
    
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int s, num;
        cin >> s;
        // 남자일 때
        if (s == 1) {
            cin >> num;
            for (int j=num; j<=n; j+=num) {
                button[j] = !button[j];
            }
        } else { // 여자일 때
            cin >> num;
            int k1 = num;
            int k2 = num;
            while (2 <= k1 && k2 <= n-1) {
                if (button[k1-1] == button[k2+1]) {
                    k1--;
                    k2++;
                } else {
                    break;
                }
            }
            for (int k=k1; k<=k2; k++) {
                button[k] = !button[k];
            }
        }
    }
    
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (cnt == 20){
            cout << '\n';
            cnt = 0;
        }

        cout << button[i] << ' ';
        cnt++;
    }
    
    return 0;
}