class Solution {
public:

bool fun(vector<int>&nums,int i,int n,int sum,int totalSum,vector<vector<int>>&dp) {

    if(i == n) {
        if(totalSum == sum) return true;
        return false;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    // pick

    int pick = fun(nums,i+1,n,sum+nums[i],totalSum-nums[i],dp);

    // non-pick

    int non_pick = fun(nums,i+1,n,sum,totalSum,dp);

    return dp[i][sum] = pick || non_pick;

    

}
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto it : nums) {
            totalSum += it;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(1e5,-1));
        return fun(nums,0,nums.size(),0,totalSum,dp);
    }
};