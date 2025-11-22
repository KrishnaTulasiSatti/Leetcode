class Solution {
public:
    // vector<vector<int>>dp;

    // int fun(vector<vector<int>>& grid,int i,int j,int m) {
    //     int n = grid[i].size();

    //     if(i == m-1) return grid[i][j];

    //     if(i < 0 || j < 0 || i >= m || j >= n) return INT_MAX;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int d1 = fun(grid,i+1,j,m);
    //     int d2 = fun(grid,i+1,j+1,m);

    //     return dp[i][j] = grid[i][j] + min(d1,d2);


    // }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();

        // dp.resize(m,vector<int>(m,-1));

        // int ans = fun(grid,0,0,m);
        // return ans;

        vector<vector<int>>dp(m,vector<int>(m));

        for(int j = m-1 ;  j >= 0 ; j--) dp[m-1][j] = grid[m-1][j];

        for(int i = m-1 ; i >= 0 ; i--) {
            for(int j = grid[i].size()-1 ; j >= 0 ; j--) {
                if(i == m-1) continue;

                int s1 = INT_MAX;
                int s2 = INT_MAX;

                if(i+1 < m) s1 = dp[i+1][j];
                if(i+1 < m && j+1 < grid[i+1].size()) s2 = dp[i+1][j+1];

                dp[i][j] = grid[i][j] + min(s1,s2);

            }
        }

        return dp[0][0];
    }
};