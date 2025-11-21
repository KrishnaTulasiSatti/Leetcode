class Solution {
public:

    // vector<int>dp;

    // int fun(vector<int>&nums,int i,int n) {

    //     if(i == n-1) return nums[i];

    //     if(i >= n) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     int pick = nums[i]+fun(nums,i+2,n);
    //     int not_pick = fun(nums,i+1,n);

    //     return dp[i] = max(pick,not_pick);


    // }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // dp.resize(n,-1);

        // int ans = fun(nums,0,n);
        // return ans;

        vector<int>dp(n+1);
        dp[n-1] = nums[n-1];

        for(int i = n-2 ; i >= 0 ; i--) {
            int pick = nums[i] + dp[i+2];
            int not_pick = dp[i+1];

            dp[i] = max(pick,not_pick);
        }

        return dp[0];
    }
};