#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        auto it = find(dq.begin(), dq.end(), a);
        int dist_front = distance(dq.begin(), it);
        int dist_back = dq.size() - dist_front;

        rotate(dq.begin(), it, dq.end());
        dq.pop_front();

        answer += min(dist_front, dist_back);
    }

    cout << answer;
    return 0;
}