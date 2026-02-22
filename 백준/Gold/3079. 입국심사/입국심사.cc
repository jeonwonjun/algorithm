#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    long long n, m;
    cin >> n >> m;
    vector<long long> times;
    for (int i=0; i<n; i++) {
        long long time;
        cin >> time;

        times.push_back(time);
    }
    sort(times.begin(), times.end());

    long long low = 1;
    long long high = m * times[0];
    long long mid;
    long long people;
    long long answer = 0;
    while (low <= high) {
        people = 0;
        mid = (high + low) / 2;
        for (int i=0; i<n; i++) {
            people += (mid / times[i]);
        }

        if (people >= m) {
            high = mid - 1;
            answer = mid;
        } else
            low = mid + 1;
    }
    cout << answer;
    return 0;
}