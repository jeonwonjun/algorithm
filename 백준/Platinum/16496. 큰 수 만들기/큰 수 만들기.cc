#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareStrings(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strings.push_back(str);
    }

    sort(strings.begin(), strings.end(), compareStrings);

    string answer = "";
    for (string s : strings) {
        answer += s;
    }

    if (answer[0] == '0') {
        answer = "0";
    }

    cout << answer;
    return 0;
}