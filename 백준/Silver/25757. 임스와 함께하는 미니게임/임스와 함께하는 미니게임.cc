#include <iostream>
#include <unordered_map>

using namespace std;
int answer = 0;

void progress(int k, int n) {
    int cnt = 0;
    unordered_map<string, int> human;
    for (int i=0; i<n; i++) {
        string nickname;
        cin >> nickname;
        if (human[nickname] < 1) {
            human[nickname]++;
            cnt++;
        }
        
        if (cnt == k) {
            answer++;
            cnt = 0;
        }
    }
}

int main() {
    int n;
    char game;
    cin >> n >> game;
    if (game == 'Y') {
        progress(1, n);
    } else if (game == 'F') {
        progress(2, n);
    } else if (game == 'O') {
        progress(3, n);
    }
    
    cout << answer << "\n";
    
    return 0;
}