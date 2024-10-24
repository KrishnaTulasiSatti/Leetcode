class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        // State : No of ways to reach (i,j) from (0,0) without obstacles
       // Transition : 
    //          dp[i][j] = dp[i-1][j]+dp[i][j-1] if (i-1,j) = 0 (i,j-1) = 0
    //          dp[i][j] = d[i-1][j]  if(i-1,j) = 0
    //          dp[i][j] = dp[i][j-1] if(i,j-1) = 0
       // Base case : (0,0) = 1 return 0
       //             (0,1) = 1 && (1,0) = 1 return 0;
       // Final Ans : dp[m-1][n-1]
       int dp[1000][1000];
       memset(dp,0,sizeof(dp));
       int m = grid.size();
       int n = grid[0].size();
       if(grid[0][0] == 1) return 0;
       else dp[0][0] = 1;
       if(m > 1 && n > 1) {
         if(grid[0][1] == 1 && grid[1][0] == 1) return 0;
       }
       for(int i = 0 ; i < m ; i++) {
         for(int j = 0 ; j < n ; j++) {
            if(i == 0 && j == 0) continue;
            int a = 0,b = 0;
            if(grid[i][j] == 1) dp[i][j] = 0;
            else{
                if((i-1) >= 0) a = dp[i-1][j];
                if((j-1) >= 0) b = dp[i][j-1];
                dp[i][j] = a+b;
            }
         }
       }
       return dp[m-1][n-1];
    }
};