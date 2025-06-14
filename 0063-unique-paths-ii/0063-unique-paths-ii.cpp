class Solution {
public:

int fun(vector<vector<int>>&mat,int i,int j,int m,int n,vector<vector<int>>&dp) {
    if(i == m-1 && j == n-1 && mat[i][j] != 1) return 1;

    if(i >= m || j >= n) return 0;

    if(mat[i][j] == 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int r = fun(mat,i,j+1,m,n,dp);
    int b = fun(mat,i+1,j,m,n,dp);

    return dp[i][j] = r+b;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(obstacleGrid,0,0,m,n,dp);
    }
};