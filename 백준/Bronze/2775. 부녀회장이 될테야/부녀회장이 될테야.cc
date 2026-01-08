#include <iostream>
using namespace std;

int dp[15][16];

int main() 
{
  for (int j=1; j<=14; j++) {
    dp[0][j] = j;
  }
    
  for (int i=1; i<=14; i++) {
    for (int j=1; j<=14; j++) {
      dp[i][j] =  dp[i][j-1] + dp[i-1][j];
    }
  }
  
  int t;
  cin >> t;
  for (int i=0; i<t; i++) {
    int k, n;
    cin >> k;
    cin >> n;
    cout << dp[k][n] << '\n';
  }
  
  return 0;
}