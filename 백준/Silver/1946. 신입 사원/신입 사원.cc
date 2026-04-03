#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int answer = 0;
        vector<pair<int, int>> rank(n);
        for (int i = 0; i < n; i++) {
            cin >> rank[i].first >> rank[i].second;
        }
        sort(rank.begin(), rank.end());
        int min = 100001;
        for (int a = 0; a < n; a++) {
            if (min > rank[a].second) {
                min = rank[a].second;
                answer++;
            }
        }
        cout << answer << '\n';
    }
    
    return 0;
}