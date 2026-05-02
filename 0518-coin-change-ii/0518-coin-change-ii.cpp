class Solution {
public:

    vector<vector<int>>dp;

    int fun(vector<int>&coins, int ind, int target) {

        if(ind < 0) {
            if(target == 0) return 1;
            else return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int pick = 0;
        int not_pick = fun(coins,ind-1,target);

        if(coins[ind] <= target) pick = fun(coins,ind,target-coins[ind]);

        return dp[ind][target] = pick + not_pick;

    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans = fun(coins,n-1,amount);
        return dp[n-1][amount];
    }
};