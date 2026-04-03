class Solution {
public:
    int m,n;

    vector<vector<vector<int>>>dp;

    int fun(vector<vector<int>>& coins,int i,int j,int cnt) {

        if(i < 0 || j < 0 || i >= m || j >= n) return -1e9;

        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && cnt < 2) return 0;
            return coins[i][j];
        }
        
        int right = -1e9, down = -1e9;
        int r1 = -1e9, d1 = -1e9;

        if(dp[i][j][cnt] != INT_MIN) return dp[i][j][cnt]; 

        right = coins[i][j] + fun(coins,i,j+1,cnt);
        down = coins[i][j] + fun(coins,i+1,j,cnt);

        if(cnt < 2 && coins[i][j] < 0) {
            r1 = fun(coins,i,j+1,cnt+1);
            d1 = fun(coins,i+1,j,cnt+1);
        }
        

        return dp[i][j][cnt] = max({right,down,r1,d1});

    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        dp.resize(m,vector<vector<int>>(n,vector<int>(4,INT_MIN)));

        return fun(coins,0,0,0);

    }
};