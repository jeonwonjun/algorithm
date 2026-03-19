#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    vector<int> cranes;
    vector<int> boxes;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int crane_weight;
        cin >> crane_weight;

        cranes.push_back(crane_weight);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int box_weight;
        cin >> box_weight;

        boxes.push_back(box_weight);
    }

    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    if (cranes[0] < boxes[0]) {
        cout << -1;
        return 0;
    }

    vector<bool> visited(m, false);

    int answer = 0;
    int moved = 0;
    while (moved < m) {
        int idx = 0;

        for (int i = 0; i < n; i++) {
            while (idx < m) {
                if (!visited[idx] && cranes[i] >= boxes[idx]) {
                    visited[idx] = true;
                    moved++;
                    idx++;
                    break;
                }
                idx++;
            }
        }

        answer++;
    }
    
    cout << answer;
    return 0;
}