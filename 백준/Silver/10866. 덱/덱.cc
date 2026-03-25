#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        int x;
        if (command == "push_front") {
            cin >> x;
            dq.push_front(x);
            continue;
        } else if (command == "push_back") {
            cin >> x;
            dq.push_back(x);
            continue;
        } else if (command == "pop_front") {
            if (dq.empty()) {
                cout << -1;
            } else {
                cout << dq.front();
                dq.pop_front();
            }
        } else if (command == "pop_back") {
            if (dq.empty()) {
                cout << -1;
            } else {
                cout << dq.back();
                dq.pop_back();
            }            
        } else if (command == "size") {
            cout << dq.size();
        } else if (command == "empty") {
            if (dq.empty()) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else if (command == "front") {
            if (dq.empty()) {
                cout << -1;
            } else {
                cout << dq.front();
            }
        } else if (command == "back") {
            if (dq.empty()) {
                cout << -1;
            } else {
                cout << dq.back();
            }
        }

        cout << '\n';
    }
    return 0;
}