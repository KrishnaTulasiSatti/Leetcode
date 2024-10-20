class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>frq;
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxi = 0;
        while(r < n) {
            frq[s[r]]++;
            while(frq[s[r]] > 1) {
                frq[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};