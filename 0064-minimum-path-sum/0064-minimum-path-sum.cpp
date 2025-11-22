class Solution {
public:
    // vector<vector<int>>dp;

    // int fun(vector<vector<int>>&grid,int i,int j,int m,int n) {
    //     if(i == m-1 && j == n-1) return grid[i][j];

    //     if(i < 0 || j < 0 || i >= m || j >= n) return INT_MAX;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int right = fun(grid,i,j+1,m,n);
    //     int bottom = fun(grid,i+1,j,m,n);

    //     return dp[i][j] = grid[i][j] + min(right,bottom);
    // }
    int minPathSum(vector<vector<int>>& grid) {

      int m = grid.size();
      int n = grid[0].size();

    //   dp.resize(m,vector<int>(n,-1));

    //   int ans = fun(grid,0,0,m,n);

    //   return ans;

    vector<vector<int>>dp(m,vector<int>(n));

    dp[m-1][n-1] = grid[m-1][n-1];

    for(int i = m-1 ; i >= 0 ; i--) {
        for(int j = n-1 ; j >= 0 ; j--) {
            if(i == m-1 && j == n-1) continue;

            int right = INT_MAX;
            int left = INT_MAX;

            if(j+1 < n) right = grid[i][j] + dp[i][j+1];
            if(i+1 < m) left = grid[i][j] + dp[i+1][j];

            dp[i][j] = min(right,left);
        }
    }

    return dp[0][0];

    }
};