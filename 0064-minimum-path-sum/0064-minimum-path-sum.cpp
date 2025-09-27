class Solution {
public:

int fun(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&dp) {

    if(i == m-1 && j == n-1) return grid[i][j];

    if(i >= m ||  j >= n) return 300000;

    if(dp[i][j] != -1) return dp[i][j];

    int r = grid[i][j] + fun(grid,i,j+1,m,n,dp);

    int d = grid[i][j] + fun(grid,i+1,j,m,n,dp);

    return dp[i][j] = min(r,d);
}
    int minPathSum(vector<vector<int>>& grid) {
       

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = fun(grid,0,0,m,n,dp);
        return ans;
    }
};