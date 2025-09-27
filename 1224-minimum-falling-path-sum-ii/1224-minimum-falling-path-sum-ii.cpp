class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i = 0 ; i < n ; i++) {
            dp[0][i] = grid[0][i];
        }


        for(int i = 1 ; i < n ; i++) {

            for(int j = 0 ; j < n ; j++) {
                
                int temp = dp[i-1][j];

                dp[i-1][j] = INT_MAX;

                dp[i][j] = grid[i][j] + (*min_element(dp[i-1].begin(),dp[i-1].end()));

                dp[i-1][j] = temp;
            }
        }

        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};