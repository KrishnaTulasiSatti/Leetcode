class Solution {
public:
vector<int>dp;
int fun(vector<int>&nums,int ind,int n) {

    if(ind >= n) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    // Pick the element

    int pick = nums[ind]+fun(nums,ind+2,n);

    // Not Pick the element

    int non_pick = fun(nums,ind+1,n);

    return dp[ind] = max(pick,non_pick);
}
    int rob(vector<int>& nums) {

        dp.resize(nums.size(),-1);

        return fun(nums,0,nums.size());
    }
};