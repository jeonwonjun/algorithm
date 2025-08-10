#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    int k = 1;
    while(t--) {
        vector<long long> v1, v2;
        cin >> n;
        
        int a;
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                cin >> a;
                if (i == 0) {
                    v1.push_back(a);
                }
                else {
                    v2.push_back(a);
                }
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<>());
        
        long long sum = 0;
        for (int i=0; i<n; i++) {
            sum += v1[i]*v2[i];
            }
            printf("Case #%d: %lld\n", k++, sum);
        }

    return 0;
}