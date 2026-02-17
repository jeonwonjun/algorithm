#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_map<string, int> dance;
    dance["ChongChong"]++;
    for (int i=0; i<n; i++) {
        string dancer1, dancer2;
        cin >> dancer1 >> dancer2;
        if (dance[dancer1] > 0 || dance[dancer2] > 0) {
            dance[dancer1]++;
            dance[dancer2]++;
        }
    }

    int answer = 0;
    for (auto dancer : dance) {
        if (dancer.second > 0) {
            answer++;
        }
    }
    cout << answer;
    return 0;
}