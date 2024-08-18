class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            int ones = 0,zeroes = 0;
            for(int j = i ; j < s.size() ; j++) {
               if(s[j] == '0') zeroes++;
               else ones++;
               if(ones <= k || zeroes <= k) cnt++;

            }
            
       }
       return cnt;
    }
};