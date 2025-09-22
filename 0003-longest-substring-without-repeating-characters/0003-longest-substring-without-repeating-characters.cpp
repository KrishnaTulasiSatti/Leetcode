class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int r = 0;

        int maxi = 0;

        unordered_map<char,int>m;

        while(r < s.size()) {

            m[s[r]]++;

            while((r-l+1) > m.size()) {
                m[s[l]]--;

                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi;
    }
};