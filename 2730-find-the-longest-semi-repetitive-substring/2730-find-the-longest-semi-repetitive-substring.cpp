class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        int n = s.size();

        int l = 0;
        int r = 0;

        int cnt = 0;

        int maxi = 0;

        while(r < n) {

            if(r-1 >= 0 && s[r] == s[r-1]) cnt++;

            cout << cnt << " " << l << " " << r << endl;

            while(cnt > 1) {
                if(l+1 < n && s[l] == s[l+1]) cnt--;
                l++;
            }

          

            if(cnt <= 1) maxi = max(maxi,r-l+1);
            r++;
        }

        // maxi = max(maxi,r-l+1);

        return maxi;
    }
};