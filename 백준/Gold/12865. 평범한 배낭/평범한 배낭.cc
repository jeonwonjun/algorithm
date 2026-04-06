#include <iostream>
#include <vector>
using namespace std;
int n, k, w, v;
int dp[100001];

int main() {
    cin >> n >> k;
    vector<int> weight;
    vector<int> value;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }

    for (int i = 0; i < n; i++) {
        for (int w = k; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[k];
    return 0;
}