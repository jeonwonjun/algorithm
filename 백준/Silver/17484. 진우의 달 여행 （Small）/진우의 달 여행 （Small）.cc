#include <iostream>
#include <algorithm>
using namespace std;

int space[6][6];
int dp[7][7][3];

int dx[3] = {-1, 0, 1};

const int INF = 1e9;

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        cin >> space[i][j];
        for (int d=0; d<3; d++) {
          dp[i][j][d] = INF;
        }
      }
    }
    
    for (int j=0; j<m; j++) {
      for (int d=0; d<3; d++) {
        dp[0][j][d] = space[0][j];
      }
    }
    
    // DP 진행
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 3; d++) {
                int prevCol = j - dx[d];
                if (prevCol < 0 || prevCol >= m) continue;

                for (int prevDir = 0; prevDir < 3; prevDir++) {
                    if (prevDir == d) continue; // 같은 방향 연속 금지

                    dp[i][j][d] = min(
                        dp[i][j][d],
                        dp[i - 1][prevCol][prevDir] + space[i][j]
                    );
                }
            }
        }
    }
    
    int answer = INF;
    for (int j = 0; j < m; j++) {
        for (int d = 0; d < 3; d++) {
            answer = min(answer, dp[n - 1][j][d]);
        }
    }

    cout << answer;

    return 0;
}