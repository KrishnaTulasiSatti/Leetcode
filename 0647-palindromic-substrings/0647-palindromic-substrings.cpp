class Solution {
public:
    int countSubstrings(string s) {
        
        int cnt = 0;

        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));

        for(int i = s.size()-1 ; i >= 0 ; i--) {

            for(int j = i ; j < s.size() ; j++) {

                if(i == j) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 1;
                        cnt++;
                    }
                }
                else if(i+1 == j) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 1;
                        cnt++;
                    }
                }
                else {
                    if(s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = 1;
                        cnt++;
                    }
                }

            }
        }
        return cnt;
    }
};