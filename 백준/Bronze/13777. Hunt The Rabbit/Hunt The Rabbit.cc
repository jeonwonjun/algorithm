#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  vector<int> card(51);
  for (int i=1; i<=50; i++) {
    card[i] = i;
  }

  int n;
  while (cin >> n) {
    int start = 1;
    int end = 50;
    if (n == 0) break;
    
    while (start <= end) {
      int mid = start + (end - start) / 2;
      cout << mid << ' ';
      if (mid == n) {
        break;
      } else if (mid < n) {
        start = mid+1;
      } else if (mid > n) {
        end = mid-1;
      }
    }
    
    cout << '\n';
  }

  return 0;
}