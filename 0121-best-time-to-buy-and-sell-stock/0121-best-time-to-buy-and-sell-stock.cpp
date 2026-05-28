class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx = prices.size() - 1;
        int max_stock = 0;

        int j = idx - 1;
        while (idx > 0 && j >= 0) {
            if (prices[j] > prices[idx]) {
                idx = j;
                j = idx - 1;
            } else {
                max_stock = max(max_stock, prices[idx] - prices[j]);
                j--;
            }
        }

        return max_stock;
    }
};