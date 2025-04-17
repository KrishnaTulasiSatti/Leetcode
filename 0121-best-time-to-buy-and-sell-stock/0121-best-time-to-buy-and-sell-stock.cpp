class Solution {
public:
    // One Transaction
    int maxProfit(vector<int>& prices) {
          int mini = prices[0];
          int maxProfit = 0;

          for(int i = 1 ; i < prices.size() ; i++) {
              mini = min(mini,prices[i]);
              maxProfit = max(maxProfit,prices[i]-mini);
          }

          return maxProfit;
    }
};