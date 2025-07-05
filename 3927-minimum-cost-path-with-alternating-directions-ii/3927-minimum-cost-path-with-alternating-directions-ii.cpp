class Solution {
public:

    uint64_t fun(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<uint64_t>>&dp) {
        if(i == m-1 && j == n-1) {
            return 1LL*(i+1)*(j+1);
        }

        if(i < 0 || i >= m || j < 0 || j >= n) return UINT64_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        if(i == 0 && j == 0) grid[i][j] = 0;

        uint64_t val = 1LL * (i+1)*(j+1) + grid[i][j];
        
        uint64_t r = fun(grid,i,j+1,m,n,dp);
        uint64_t d = fun(grid,i+1,j,m,n,dp);


        return dp[i][j] = val + min(r,d);
    }
    uint64_t minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<uint64_t>>dp(m,vector<uint64_t>(n,-1));
        uint64_t ans = fun(waitCost,0,0,m,n,dp);
        return ans;
    }
};