class Solution {
    int mod = 1_000_000_007;
    public int solution(int n) {
        int answer = 0;
        
        int[] dp = new int[60_000];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        dp[3] = dp[3-2] + dp[3-1];
 
        for(int i=3; i<n; i++) {
            dp[i] = (dp[i-2] + dp[i-1]) % mod;
        }
        
        return dp[n-1];
    }
}