#include <iostream>
using namespace std;
int lecture[1001][5];

int main() 
{
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
      for (int j=0; j<5; j++) {
        cin >> lecture[i][j];
      }
    }
    
    int cnt[1001] = {0,};
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        bool flag = false;
        if (i == j) continue;
        for (int k=0; k<5; k++) {
          if (lecture[i][k] == lecture[j][k] && !flag) {
            flag = true;
            cnt[i]++;
          }
        }
      }
    }
    
    int answer = 1;
    int maxCnt = 0;
    for (int i=1; i<=n; i++) {
      if (maxCnt < cnt[i]) {
        answer = i;
        maxCnt = cnt[i];
      }
    }
    
    cout << answer;
    return 0;
}