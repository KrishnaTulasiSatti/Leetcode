class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        
        long long org = 0;

        for(int i = 0 ; i < prices.size() ; i++) {
            org += (strategy[i] * prices[i]);
        }

       // cout << org << endl;

        long long maxi = org;

        long long sum = maxi;

        for(int i = 0 ; i < k ; i++) {
            sum -= (prices[i]*strategy[i]);

            if(i+1 > k/2) sum += prices[i];
        }
       // cout << sum << endl;
        maxi = max(maxi,sum);

        int l = 0;
        int r = k;
        int x = k/2;
        while(r < prices.size()) {
            sum += (strategy[l]*prices[l]);
            sum -= (strategy[r]*prices[r]);
            sum += prices[r];
            sum -= prices[x++];
            maxi= max(maxi,sum);
            l++;
            r++;
        }

        return maxi;


        
    }
};