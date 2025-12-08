#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> human;
    for (int i=0; i<n; i++) {
        int w, h;
        cin >> w >> h;
        human.push_back({w, h});
    }
    
    for (int i=0; i<n; i++) {
        int answer = 1;
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            
            if ((human[i].first < human[j].first) && human[i].second < human[j].second) {
                answer++;
            }
        }
        cout << answer << " ";
    }

    return 0;
}