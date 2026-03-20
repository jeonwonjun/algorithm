#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> jewels;
    vector<int> bags;

    for (int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;

        jewels.push_back({m, v});
    }

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;

        bags.push_back(c);
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long answer = 0;
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && bags[i] >= jewels[j].first) {
            pq.push(jewels[j].second);
            j++;
        }
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
    return 0;
}