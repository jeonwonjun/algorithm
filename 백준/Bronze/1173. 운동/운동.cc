#include <iostream>
using namespace std;

int main() 
{
  int N, m, M, T, R;
  cin >> N >> m >> M >> T >> R;
  
  int i = 0;
  int heart = m;
  int cnt = 0;
  while (i < N) {
    if (m + T > M) {
      cout << -1;
      return 0;
    }
    
    if (heart + T <= M) {
      i++;
      heart += T;
    } else if (heart + T > M) {
      if (heart - R < m) {
        heart = m;
      } else {
        heart -= R;
      }
    }
    cnt++;
  }

  cout << cnt;
  return 0;
}