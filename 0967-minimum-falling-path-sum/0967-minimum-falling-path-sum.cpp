class Solution {
public:

int fun(vector<vector<int>>&mat,int i,int j,int m,int n,vector<vector<int>>&dp) {
    if(i == m-1 && j < n && j >= 0) return mat[i][j];

    if(i < 0 || j < 0 || i >= m || j >= n) return 1e9;

    if(dp[i][j] != INT_MIN) return dp[i][j];

    int dl = mat[i][j] + fun(mat,i+1,j-1,m,n,dp);
    int b = mat[i][j] + fun(mat,i+1,j,m,n,dp);
    int dr = mat[i][j] + fun(mat,i+1,j+1,m,n,dp);

    return dp[i][j] = min({dl,b,dr}); 
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
       
       int mini = INT_MAX;

       int m = matrix.size();
       int n = matrix[0].size();

       vector<vector<int>>dp(m,vector<int>(n,INT_MIN));

       for(int i = 0 ; i < n ; i++){
           mini = min(mini,fun(matrix,0,i,m,n,dp));
       }

       return mini;
    }
};