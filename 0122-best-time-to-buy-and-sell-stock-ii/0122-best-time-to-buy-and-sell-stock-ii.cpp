class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int maxi = 0;

        int mini = prices[0];

        for(int i = 1 ; i < n ; i++) {

            if(prices[i] < prices[i-1]) {
                maxi += prices[i-1]-mini;
                mini = prices[i];
            }
            else mini = min(mini,prices[i]);
            
        }

        maxi += prices[n-1]-mini;

        return maxi;
    }
};