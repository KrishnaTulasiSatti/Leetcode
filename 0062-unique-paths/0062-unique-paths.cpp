class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[1000][1000];
        memset(dp,0,sizeof(dp));
        // dp[i][j] = dp[i-1][j]+dp[i][j-1];
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[1][0] = 1;
        dp[1][1] = 2;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) && (i == 1 && j == 1)) continue;
                int a = 0 , b = 0;
                if((i-1 >= 0)) a = dp[i-1][j];
                if((j-1 >= 0)) b = dp[i][j-1];
                dp[i][j] = a+b;
            }
        }
        return dp[m-1][n-1];

    }
};