#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rope;
    for (int i=0; i<n; i++) {
        int rope_weight;
        cin >> rope_weight;
        rope.push_back(rope_weight);
    }

    sort(rope.begin(), rope.end());

    int answer = 0;
    for (int i=0; i<n; i++) {
        answer = max(answer, rope[i]*(n-i));
    }

    cout << answer;
    return 0;
}