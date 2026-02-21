#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include <numeric>
using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    vector<pair<int, int>> count;

    double sum = 0;
    for (int i=0; i<n; i++) {
        int number;
        cin >> number;
        nums.push_back(number);

        sum += number;
    }

    sort(nums.begin(), nums.end());

    int avg = (int)round(sum / n);

    cout << avg << '\n';
    cout << nums[n/2] << '\n';

    for (int i=0; i<nums.size(); i++) {
        if (count.empty()) {
            count.push_back({nums[i], 1});
            continue;
        }

        if (count.back().first == nums[i]) {
            pair<int, int> tmp = count.back();
            tmp.second++;
            count.pop_back();
            count.push_back(tmp);
        } else {
            count.push_back({nums[i], 1});
        }
    }

    sort(count.begin(), count.end(), comp);

    if (count[0].second == count[1].second)
        cout << count[1].first << '\n';
    else
        cout << count[0].first << '\n';

    cout << nums[n-1] - nums[0] << '\n'; 
    return 0;
}