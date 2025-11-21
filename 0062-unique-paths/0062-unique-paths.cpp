class Solution {
public:

    // vector<vector<int>>dp;

    // int fun(int i,int j,int m,int n) {

    //     if(i == m-1 && j == n-1) return 1;

    //     if(i < 0 || j < 0 || j >= n || i >= m) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int right = fun(i,j+1,m,n);
    //     int bottom = fun(i+1,j,m,n);

    //     return dp[i][j] = right + bottom;

    // }

    int uniquePaths(int m, int n) {

        // dp.resize(m,vector<int>(n,-1));
        // int ans = fun(0,0,m,n);
        // return ans;

        vector<vector<int>>dp(m,vector<int>(n));

        dp[m-1][n-1] = 1;

        for(int i = m-1 ; i >= 0 ; i--) {
            for(int j = n-1 ; j >= 0 ; j--) {
                if(i == m-1 && j == n-1) continue;

                int right = 0,bottom = 0;

                if(j+1 < n) right = dp[i][j+1];
                if(i+1 < m) bottom = dp[i+1][j];

                dp[i][j] = right+bottom;
            }
        }

        return dp[0][0];
    }
};