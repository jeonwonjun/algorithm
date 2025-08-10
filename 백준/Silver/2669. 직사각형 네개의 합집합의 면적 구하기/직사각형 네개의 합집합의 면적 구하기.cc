#include <iostream>
using namespace std;

int map[101][101];

int main() {
    
    int a, b, c, d;
    int ans=0;
    for (int i=0; i<4; i++) {
        cin >> a >> b >> c >> d;
        for (int x=a; x<c; x++) {
            for (int y=b; y<d; y++) {
                if (!map[x][y]) {
                    ans++;
                    map[x][y] = 1;
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}