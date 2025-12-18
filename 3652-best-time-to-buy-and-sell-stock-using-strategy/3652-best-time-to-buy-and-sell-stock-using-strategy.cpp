class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        

        long long total = 0;

        for(int i = 0 ; i < prices.size() ; i++) {
            total += (strategy[i] * prices[i]); 
        }

        long long maxi = total;

        long long sum = total;

        for(int i = 0 ; i < k ; i++) {
            sum -= (prices[i] * strategy[i]);

            if(i+1 > k/2) sum += prices[i];
        }
    
        // cout << sum << endl;
        maxi = max(maxi,sum);

        int l = 0;
        int r = k;
        int mid = k/2;
        while(r < prices.size()) {
            sum += (strategy[l]*prices[l]);
            sum -= (strategy[r]*prices[r]);
            sum += prices[r];
            sum -= prices[mid++];
            maxi= max(maxi,sum);
            l++;
            r++;
        }

        return maxi;


        
    }
};