class Solution {
public:

    vector<vector<vector<int>>>dp;

    const int mod = 1e9 + 7;

    int fun(int i,int j,int m,int n,int maxMove,int moves) {

        if(moves > maxMove) return 0;

        if(i < 0 || j < 0 || i >= m || j >= n) return 1;

        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        long long t = fun(i-1,j,m,n,maxMove,moves+1) % mod;
        long long b = fun(i+1,j,m,n,maxMove,moves+1) % mod;
        long long l = fun(i,j-1,m,n,maxMove,moves+1) % mod;
        long long r = fun(i,j+1,m,n,maxMove,moves+1) % mod;

        return dp[i][j][moves] = (1LL * (t + b + l + r)) % mod;


    }


    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        dp.resize(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));

        return fun(startRow,startColumn,m,n,maxMove,0) % mod;

    }
};