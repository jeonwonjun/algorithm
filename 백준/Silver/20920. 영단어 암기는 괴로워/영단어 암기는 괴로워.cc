#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }

    return a.second > b.second;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    map<string, int> dictionaly;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string word;
        cin >> word;
        if (word.length() >= m) {
            dictionaly[word]++;
        }
    }

    vector<pair<string, int>> dic(dictionaly.begin(), dictionaly.end());

    sort(dic.begin(), dic.end(), compare);

    for (auto pair : dic)
        cout << pair.first << '\n';

    return 0;
}