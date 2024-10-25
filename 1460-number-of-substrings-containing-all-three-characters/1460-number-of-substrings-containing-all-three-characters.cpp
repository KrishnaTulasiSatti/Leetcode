class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        long long total = ((long long)n*(long long)(n+1))/2;
        int l = 0;
        int r = 0;
        unordered_map<char,int>m;
        while(r < n) {
           m[s[r]]++;
           while(m['a'] >= 1 && m['b'] >= 1 && m['c'] >= 1) {
             m[s[l]]--;
             l++;
           }
           cnt+=(r-l+1);
           r++;
        }
        return total-cnt;
    }
};