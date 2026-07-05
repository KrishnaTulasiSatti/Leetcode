class Solution {
public:
    bool canMakeSubsequence(string s, string t) {

        int m = s.size();
        int n = t.size();

        int i = 0;
        int j = 0;

        int r = 1;

        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                if(r == 1) {
                    i++;
                    j++;
                    r = 0;
                }
                else {
                    j++;
                }
            }
        }

        if(i == m) return true;

        i = m-1;
        j = n-1;
        r = 1;

        while(i >= 0 && j >= 0) {
            if(s[i] == t[j]) {
                i--;
                j--;
            }
            else {
                if(r == 1) {
                    i--;
                    j--;
                    r = 0;
                }
                else j--;
            }
        }

        if(i < 0) return true;
        return false;
    }
};