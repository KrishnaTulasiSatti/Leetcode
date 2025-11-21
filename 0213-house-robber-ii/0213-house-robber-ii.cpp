class Solution {
public:
   
    int fun(vector<int>&nums,int i,int n,vector<int>&dp) {
        if(i == n-1) return nums[i];

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + fun(nums,i+2,n,dp);
        int not_pick = fun(nums,i+1,n,dp);

        return dp[i] = max(pick,not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int>dp1(n,-1);

        int first = fun(nums,0,n-1,dp1);

        vector<int>dp2(n,-1);

        int last = fun(nums,1,n,dp2);

        return max(first,last);
    }
};