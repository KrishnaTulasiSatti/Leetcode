class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        string res = "";

        for(int i = 0 ; i < n ; i++) {
            dp[i][i] = 1;
            res = s.substr(i,1);
        }

        for(int i = 0 ; i < n-1 ; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                res = s.substr(i,2);
            }
            
        }

        
        for(int len = 3 ; len <= n ; len++) {
            int j = n-len;
            for(int i = 0 ; i <= j ; i++) {
                int k = i+len-1;
                if(s[i] == s[k] && dp[i+1][k-1] == 1) {
                    dp[i][k] = 1;
                    res = s.substr(i,len);
                }
            }
        }

        return res;
    }
};