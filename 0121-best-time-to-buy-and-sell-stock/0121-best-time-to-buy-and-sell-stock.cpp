class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[100001] = {0, };
        
        dp[0] = 0;
        int min_idx = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] >= prices[min_idx])
                dp[i] = dp[min_idx];
            else if (prices[i] < prices[min_idx]) {
                dp[i] = i;
                min_idx = i;
            }
            
        }

        // for (int i = 0; i<prices.size(); i++)
        //     cout << dp[i] << " ";

        int ans = 0;
        for (int i=0; i<prices.size(); i++) {
            ans = max(ans, prices[i] - prices[dp[i]]);
        }

        return ans;
    }
};