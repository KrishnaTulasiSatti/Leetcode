class Solution {
public:

int dp[301][301][100];
const int mod = 1e9+7;
int fun(vector<vector<int>>&grid,int i,int j,int k,int xr,int n,int m) {
    if(i >= n || j >= m) return 0;

    if(dp[i][j][xr] != -1) return dp[i][j][xr];

    if(i == n-1 && j == m-1) {
        xr^=grid[i][j];
        if(xr == k) return 1;
        else return 0;
    }

    return dp[i][j][xr] = ((fun(grid,i+1,j,k,xr^grid[i][j],n,m) % mod)+(fun(grid,i,j+1,k,xr^grid[i][j],n,m) % mod)) % mod;
    
}
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int res = fun(grid,0,0,k,0,n,m);
        return res % mod;
    }
};