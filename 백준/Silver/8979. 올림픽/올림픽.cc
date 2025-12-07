#include <iostream>
#include <vector>

using namespace std;

struct Country {
    int id;
    int g, s, b;
};

int main() {
    // 입력 받기
    int n, k;
    cin >> n >> k;
    vector<Country> v;
    
    int gk = 0, sk = 0, bk = 0;
    
    for (int i=0; i<n; i++) {
        int id, g, s, b;
        cin >> id >> g >> s >> b;
        v.push_back({id, g, s, b});
        
        if (id == k) {
            gk = g;
            sk = s;
            bk = b;
        }
    }
    
    int better = 0;
    for (auto c : v) {
        if (c.id == k) continue;
        
        bool isBetter = false;
        
        if (c.g > gk) {
            isBetter = true;
        } else if (c.g == gk && c.s > sk) {
            isBetter = true;
        } else if (c.g == gk && c.s == sk && c.b > bk) {
            isBetter = true;
        }
        
        if (isBetter) {
            better++;
        }
    }
    
    cout << better + 1 << '\n';

    return 0;
}