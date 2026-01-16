#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int ingredient = 1 << n;
    vector<int> sours;
    vector<int> bitters;
    for (int i=0; i<n; i++) {
      int sour, bitter;
      cin >> sour >> bitter;
      sours.push_back(sour);
      bitters.push_back(bitter);
    }
    
    int min_diff = INT_MAX;
    for (int mask = 0; mask < ingredient; ++mask) {
      if (__builtin_popcount(mask) >= 1) {
        int sum = 0;
        int mul = 1;
        for (int i = 0; i < n; ++i) {
          if (mask & (1 << i)) {
            mul *= sours[i];
            sum += bitters[i];
          }
        }
        int diff = abs(mul - sum);
        min_diff = min(min_diff, diff);
      }
    }
    cout << min_diff;
    return 0;
}