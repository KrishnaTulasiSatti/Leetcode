class Solution {
public:
int fun(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&dp) {
    int m = mat.size();
    int n = mat[i].size();

    if(i == m-1 && j <= n-1) return mat[i][j];

    if(i >= m || j >= n) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];

    int step1 = mat[i][j] + fun(mat,i+1,j,dp);
    int step2 = mat[i][j] + fun(mat,i+1,j+1,dp);

    return dp[i][j] = min(step1,step2);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(triangle,0,0,dp);
    }
};