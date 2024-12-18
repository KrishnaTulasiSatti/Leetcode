class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       vector<int>ans;
       for(int i = 0 ; i < prices.size() ; i++) {
          int mini = prices[i];
          int f = 0;
          for(int j = i+1 ; j < prices.size() ; j++) {
              if(prices[j] <= mini) {
                mini = prices[j];
                f = 1;
                break;
              }
          }

          if(f == 0) {
            ans.push_back(prices[i]);
          }
          else {
            ans.push_back(prices[i]-mini);
          }
       }
        return ans;
    }
};