#include <string>
#include <vector>
#include <cstring>

using namespace std;
int a;
int b;
int dp[41][121][121];
int ans = 1e9;

int go(int index, int A, int B, vector<vector<int>> &info) {
    // 1. 불가능한 경우
    if (A >= a || B >= b) return 1e9;
    // 2. 종료조건
    if (index == info.size()) return A;
    if (dp[index][A][B] != -1) return dp[index][A][B];
    
    // 3. 다음 경우
    // 3-1. A가 훔친 경우
    int a1 = go(index+1, A+info[index][0], B, info);
    // 3-2. B가 훔친 경우
    int b1 = go(index+1, A, B+info[index][1], info);
    
    return dp[index][A][B] = min(a1, b1);
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    a = n, b = m;
    memset(dp, -1, sizeof(dp));  // dp 초기화
    
    answer = go(0, 0, 0, info);
    if (answer == 1e9) return -1; // 불가능한 경우
    
    return answer;
}