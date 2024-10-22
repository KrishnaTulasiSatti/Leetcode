class Solution {
public:
int dp[1000][1000];
int fun(vector<vector<int>>&grid,int i,int j,int n,int m,int val,int cnt) {
    if(i < 0 || j < 0 || i >= n || j >= m) return cnt-1;
    if(val >= grid[i][j]) return cnt-1;
    if(dp[i][j] != -1) return dp[i][j];
    int l = fun(grid,i,j+1,n,m,grid[i][j],cnt+1);
    int r = fun(grid,i-1,j+1,n,m,grid[i][j],cnt+1);
    int t = fun(grid,i+1,j+1,n,m,grid[i][j],cnt+1);
    return dp[i][j] = max({l,r,t});


}
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi= INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi,fun(grid,i,0,n,m,0,0));
        }
        return maxi;
    }
};