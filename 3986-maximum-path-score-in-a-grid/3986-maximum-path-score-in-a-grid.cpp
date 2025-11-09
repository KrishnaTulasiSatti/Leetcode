class Solution {
public:
    bool f = 0;
    vector<vector<vector<int>>>dp;
    
    int fun(vector<vector<int>>& grid,int i,int j,int m,int n,int k,int cost) {

        if(i < 0 || j < 0 || i >= m || j >= n) return -10000;

        int s = grid[i][j];
        if(s >= 1) cost++;

        if(cost > k) return -10000;

        if(dp[i][j][cost] != -1) return dp[i][j][cost];
        

        if(i == m-1 && j == n-1) {
            if(cost <= k) {
                f = 1;
                return s;
            }
            return -10000;
        }

        int r = fun(grid,i,j+1,m,n,k,cost);
        int d = fun(grid,i+1,j,m,n,k,cost);

        return dp[i][j][cost] = grid[i][j] + max(r,d);
        
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        dp.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        int ans = fun(grid,0,0,m,n,k,0);


        if(f == 0) return -1;
        return ans;
        
        
    }
};