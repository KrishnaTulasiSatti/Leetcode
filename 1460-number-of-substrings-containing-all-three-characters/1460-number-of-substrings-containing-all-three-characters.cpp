class Solution {
public:
    int numberOfSubstrings(string s) {
    
        int l = 0;
        int r = 0;
        int n = s.size();
        long long frq[3] = {0};
        long long cnt= 0;
        while(r < n) {
          frq[s[r]-'a']++;
          int a = frq[0],b = frq[1],c = frq[2];
          while(a > 0 && b > 0 && c > 0 && l < n) {
            frq[s[l]-'a']--;
            a = frq[0] , b = frq[1] , c = frq[2];
            l++;
          }
          cnt+=(r-l)+1;
          r++;
        }
        long long res = ((long long)n*(long long)(n+1))/2;
        return res-cnt;
    }
};