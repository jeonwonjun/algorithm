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

    int answer = 0;
    while (!boxes.empty()) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (boxes.size() == 0 && i != 0) {
                answer++;
                cout << answer;
                return 0;
            }
            for (int j = 0; j < boxes.size(); j++) {
                if (cranes[i] >= boxes[j]) {
                    boxes.erase(boxes.begin() + j);
                    break;
                } else {
                    j++;
                }
            }
        }
        answer++;
    }
    
    cout << answer;
    return 0;
}