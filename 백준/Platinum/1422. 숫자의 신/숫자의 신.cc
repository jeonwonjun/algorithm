#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareInit(const string &a, const string &b) {
    return a + b > b + a;
}

bool comparseBig(const string &a, const string &b) {
    if (a.length() == b.length()) {
        return a > b;
    }

    return a.length() > b.length();
}

string calculateString(const string &a, const string &b) {
    if (a + b > b + a) {
        return a + b;
    }

    return b + a;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> numbers;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;

        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end(), comparseBig);
    string big_number = numbers[0];
    
    vector<string> temp; // 작은 값 저장 공간
    // 최종 순서
    sort(numbers.begin(), numbers.end(), compareInit);

    // 이어붙일 수보다 작은 값 저장
    while (numbers.back() < big_number) {
        temp.push_back(numbers.back());
        numbers.pop_back();
    }
    
    string answer = "";
    for (string s : numbers) {
        answer += s;
    }

    int cnt = k - temp.size() - numbers.size();
    while (cnt--) {
        answer = calculateString(answer, big_number);    
    }

    string tail = "";
    while (!temp.empty()) {
        tail = calculateString(tail, temp.back());
        temp.pop_back();
    }

    cout << answer + tail;
    return 0;
}