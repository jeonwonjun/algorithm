#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> left;
    stack<int> right;
    vector<int> height(n); // 빌딩 높이 저장
    vector<int> answer(n); // 정답 저장
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        height[i] = h;
        left.push(i);
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();

        if (left.empty()) {
            break;
        }
        
        if (height[left.top()] >= height[right.top()]) {
            while (!right.empty()) {
                if (height[left.top()] < height[right.top()])
                    break;
                answer[right.top()] = left.top() + 1;
                right.pop();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    
    return 0;
}