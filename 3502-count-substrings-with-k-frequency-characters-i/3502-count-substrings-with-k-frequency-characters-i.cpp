class Solution {
public:
int fun(string s,int k) {
    int l = 0;
    int r = 0;
    int n = s.size();
    int frq[26] = {0};
    int cnt = 0;
    while(r < n) {
        frq[s[r]-'a']++;
        while(frq[s[r]-'a'] >= k) {
            frq[s[l]-'a']--;
            l++;
        }
        cnt+=(r-l)+1;
        r++;
    }
    return cnt;
}
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int res = n*(n+1)/2;
        return res-fun(s,k);
    }
};