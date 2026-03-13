#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int k = 0; k < n; k++) {
        stack<char> a;
        stack<char> b;
        string keylog;
        cin >> keylog;

        for (int i = 0; i < keylog.length(); i++) {
            if (keylog[i] == '<') {
                if (!a.empty()) {
                    b.push(a.top());
                    a.pop();
                }
            } else if (keylog[i] == '>') {
                if (!b.empty()) {
                    a.push(b.top());
                    b.pop();                    
                }
            } else if (keylog[i] == '-') {
                if (!a.empty())
                    a.pop();
            } else {
                a.push(keylog[i]);   
            }
        }
        
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }

        while (!b.empty()) {
            cout << b.top();
            b.pop();
        }

        cout << '\n';
    }
    return 0;
}