class Solution {
public:

    vector<int>dp;

    int fun(vector<int>&cost,int i,int n) {

        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        // one step
        int one = fun(cost,i+1,n);

        // two steps
        int two = fun(cost,i+2,n);

        return dp[i] = cost[i] + min(one,two);

    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        dp.resize(n,-1);
        int ans1 = fun(cost,0,n);
        int ans2 = fun(cost,1,n);

        return min(ans1,ans2);
    }
};