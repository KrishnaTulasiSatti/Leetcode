class Solution {
public:
    vector<vector<vector<int>>>dp;
    const int mod = 1e9+7;
    int fun(vector<vector<int>>& grid,int i,int j,int m,int n,int sum,int k) {
        if(i == m-1 && j == n-1) {
            sum += grid[i][j];
            if(sum % k == 0) return dp[i][j][sum % k] =  1;
            else return 0;
        }

        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        if(dp[i][j][sum % k] != -1) return dp[i][j][sum % k];

        int r = fun(grid,i,j+1,m,n,sum+grid[i][j],k);
        int d = fun(grid,i+1,j,m,n,sum+grid[i][j],k);

        return dp[i][j][sum % k] = (r+d) % mod;


    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        int ans = fun(grid,0,0,m,n,0,k);
        return ans;
    }
};