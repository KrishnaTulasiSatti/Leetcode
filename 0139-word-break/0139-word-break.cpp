class Solution {
public:


    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        unordered_map<string,int>m;

        int maxi = 0;

        for(auto& it : wordDict) {
            m[it]++;
            maxi = max(maxi,(int)it.size());
        }

        vector<bool>dp(n+1,false);
        dp[0] = true;

        for(int i = 1 ; i <= n ; i++) {

            for(int len = 1 ; len <= maxi ; len++) {

                if(i-len < 0) break;

                string temp = s.substr(i-len,len);
                if(m.find(temp) != m.end()) {
                    if(dp[i-len] == true) dp[i] = true;
                }
            }
            
        }

        return dp[n];
    }
};