class Solution {
public:
    vector<vector<int>> dp;

    int fun(vector<int>& nums, int i, int n, int prev) {
        if (i == n) return 0;

        if (dp[i][prev+1] != -1) return dp[i][prev+1];

        int pick = 0;
        if (prev == -1 || nums[i] > nums[prev]) pick = 1 + fun(nums,i+1,n,i);
        
        int not_pick = fun(nums,i+1,n,prev);

        return dp[i][prev+1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n+1, -1));
        int res = fun(nums, 0, n, -1);
        return res;
    }
};
