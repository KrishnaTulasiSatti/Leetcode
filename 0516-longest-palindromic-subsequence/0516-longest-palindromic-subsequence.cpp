class Solution {
public:

    // vector<vector<int>>dp;

    // int fun(string s,int i,int j) {
        
    //     if(i > j) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == s[j]) {
    //         if(i != j) return dp[i][j] = 2 + fun(s,i+1,j-1);
    //         return dp[i][j] = 1 + fun(s,i+1,j-1);
    //     }

    //     int a = fun(s,i+1,j);
    //     int b = fun(s,i,j-1);


    //     return dp[i][j] = max(a,b);
    // }
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        int maxi = 1;
        
        for(int i = 0 ; i < n ; i++) dp[i][i] = 1;
        

        for(int len = 2 ; len <= n ; len++) {

            for(int i = 0 ; i <= n-len ; i++) {

                int j = i+len-1;
                
                if(s[i] == s[j]) {
                    if(len == 2) dp[i][j] = 2;
                    else dp[i][j] = 2 + dp[i+1][j-1];
                }
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                
                maxi = max(maxi,dp[i][j]);
            }
        }

        return maxi;
    }
};