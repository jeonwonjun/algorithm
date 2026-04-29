#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    int i = 1;
    while (i <= t) {
        int n, m;
        cin >> n >> m;
        vector<long long> times;
        for (int j = 0; j < n; j++) {
            int tk;
            cin >> tk;

            times.push_back(tk);
        }

        sort(times.begin(), times.end());

        long long low = 1;
        long long high = m*times[0];
        long long answer = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long total_processed = 0;

            for (int t : times) {
                total_processed += mid / t;
            }

            if (total_processed >= m) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << '#' << i++ << ' ' << answer << '\n';
    }
    return 0;
}