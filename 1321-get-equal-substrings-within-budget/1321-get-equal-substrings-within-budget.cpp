class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int cost = 0;
        int maxi = 0;
        while(r < n) {
            cost+= abs(s[r]-t[r]);
            while(cost > maxCost) {
                cost-= abs(s[l]-t[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;

    }
};