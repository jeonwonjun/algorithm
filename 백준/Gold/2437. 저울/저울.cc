#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] > answer + 1) { 
            break;
        }
        answer += weights[i];
    }

    cout << answer + 1;
    return 0;
}