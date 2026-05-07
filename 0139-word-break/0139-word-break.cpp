class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        vector<bool>dp(n+1,false);

        set<string>st;

        int maxi = 0;

        dp[0] = true;

        for(auto it : wordDict) {
            st.insert(it);
            maxi = max(maxi,(int)it.size());
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int len = 1 ; len <= maxi ; len++) {
                if(i-len < 0) break;
                string temp = s.substr(i-len,len);
                if(st.find(temp) != st.end() && dp[i-len]) {
                    dp[i] = true;
                }
            }
        }

        return dp[n];


    }
};