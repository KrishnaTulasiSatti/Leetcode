class Solution {
public:
    int maxPower(string s) {
        int maxi = 1;
        int count = 1;
         for(int i = 0 ; i < s.size() ; i++) {
           if(s[i] != s[i+1]) count = 1;
           else count++;
           maxi = max(maxi,count);
         }
         return maxi;
    }
};