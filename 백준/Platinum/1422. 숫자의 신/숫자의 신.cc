#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareInit(const string &a, const string &b) {
    return a + b > b + a;
}

bool biggerNumber(const string &a, const string &b) {
    if (a.length() == b.length()) {
        return a > b;
    }

    return a.length() > b.length();
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> numbers;
    string best = "";
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;

        numbers.push_back(num);
        if (best.empty() || biggerNumber(num, best)) {
            best = num;
        }
    }
    
    for (int i = 0; i < k - n; i++) {
        numbers.push_back(best);
    }
    sort(numbers.begin(), numbers.end(), compareInit);

    string answer = "";
    for (string s : numbers) {
        answer += s;
    }
    cout << answer;
    return 0;
}