class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        long long cnt = 0;

        int n = prices.size();

        int c = 1;

        for(int i = 1 ; i < n ; i++) {

            if(prices[i] < prices[i-1] && (prices[i-1]-prices[i]) == 1) c++;
            else {
                cnt += 1LL*c*(c+1)/2;
                c = 1;
            }

        }

        cnt += 1LL*c*(c+1)/2;

        return cnt;


    }
};