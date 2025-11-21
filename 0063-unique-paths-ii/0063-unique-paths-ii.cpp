class Solution {
public:
    vector<vector<int>>dp;

    int fun(vector<vector<int>>& grid,int i,int j,int m,int n) {

        if(i == m-1 && j == n-1 && grid[i][j] != 1) return 1;

        if(i < 0 || j < 0 || i >= m || j >= n) return 0;

        if(grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = fun(grid,i,j+1,m,n);
        int bottom = fun(grid,i+1,j,m,n);

        return dp[i][j] = right+bottom;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();

        dp.resize(m,vector<int>(n,-1));

        int ans = fun(grid,0,0,m,n);

        return ans;
    }
};