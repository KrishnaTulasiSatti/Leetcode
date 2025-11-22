class Solution {
public:
    

    // int fun(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& dp) {

       
    //     if(i < 0 || j < 0 || i >= m || j >= n) return INT_MAX;

    //     if(i == m-1) return grid[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int s1 = fun(grid,i+1,j-1,m,n,dp);
    //     int s2 = fun(grid,i+1,j,m,n,dp);
    //     int s3 = fun(grid,i+1,j+1,m,n,dp);

    //     return dp[i][j] = grid[i][j] + min({s1,s2,s3});
    // }
    int minFallingPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MAX;

       
        // for(int j = 0 ; j < n ; j++) {
        //     vector<vector<int>>dp(m,vector<int>(n,-1));
        //     ans = min(ans,fun(grid,0,j,m,n,dp));
        // }

        // return ans;

        for(int j = 0 ; j < n ; j++) {

            vector<vector<int>>dp(m,vector<int>(n));

            for(int j = 0 ; j < n ; j++) dp[m-1][j] = grid[m-1][j];

            for(int i = m-1 ; i >= 0 ; i--) {
                for(int j = n-1 ; j >= 0 ; j--) {

                    if(i == m-1) continue;
                    
                    int s1= INT_MAX,s2 = INT_MAX,s3 = INT_MAX;

                    if(i+1 < m && j-1 >= 0) s1 = grid[i][j] + dp[i+1][j-1];
                    if(i+1 < m) s2 = grid[i][j] + dp[i+1][j];
                    if(i+1 < m && j+1 < n) s3 = grid[i][j] + dp[i+1][j+1];

                    dp[i][j] = min({s1,s2,s3});



                }
            }
            ans = min(ans,dp[0][j]);

        }

        return ans;
    }
};