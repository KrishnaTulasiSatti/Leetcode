class Solution {
public:
    // vector<vector<int>>dp;

    // int fun(vector<vector<int>>& grid,int i,int j,int m,int n) {

    //     if(i == m-1 && j == n-1 && grid[i][j] != 1) return 1;

    //     if(i < 0 || j < 0 || i >= m || j >= n) return 0;

    //     if(grid[i][j] == 1) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int right = fun(grid,i,j+1,m,n);
    //     int bottom = fun(grid,i+1,j,m,n);

    //     return dp[i][j] = right+bottom;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();

        // dp.resize(m,vector<int>(n,-1));

        // int ans = fun(grid,0,0,m,n);

        // return ans;

        vector<vector<long long>>dp(m,vector<long long>(n));

        dp[m-1][n-1] = !grid[m-1][n-1];

        for(int i = m-1 ; i >= 0 ; i--) {
            for(int j = n-1 ; j >= 0 ; j--) {
                if(i == m-1 && j == n-1) continue;

                if(grid[i][j] == 1) dp[i][j] = 0;
                else {
                    long long right = 0,bottom = 0;
                    if(j+1 < n) right = dp[i][j+1];
                    if(i+1 < m) bottom = dp[i+1][j];
                    dp[i][j] = right+bottom;
                }
            }
        }

        return dp[0][0];
    }
};