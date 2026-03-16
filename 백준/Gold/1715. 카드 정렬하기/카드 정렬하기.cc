#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> cards;
    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        cards.push(card);
    }

    int answer = 0;
    while (!cards.empty()) {
        if (cards.size() == 1) {
            break;
        }
        int temp = 0;
        temp += cards.top();
        cards.pop();
        temp += cards.top();
        cards.pop();
        cards.push(temp);
        answer += temp;
    }

    cout << answer;
    return 0;
}