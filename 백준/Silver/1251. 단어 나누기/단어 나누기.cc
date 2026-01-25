#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> newWords;
void splitIntoThree(string s) {
    int n = s.length();
    if (n < 3) return;
    
    for (int i=1; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            string part1 = s.substr(0, i);
            reverse(part1.begin(), part1.end());
            string part2 = s.substr(i, j-i);
            reverse(part2.begin(), part2.end());
            string part3 = s.substr(j);
            reverse(part3.begin(), part3.end());
            string new_word = part1 + part2 + part3;
            newWords.push_back(new_word);
        }
    }
}

int main() {
    string word;
    cin >> word;

    splitIntoThree(word);
    sort(newWords.begin(), newWords.end());

    cout << newWords[0];
    return 0;
}