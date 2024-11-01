class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;
        string res;
        int frq[26] = {0};
        int l = 0;
        int r = 3;
        for(int i = 0 ; i < 3 ; i++) {
             int flag = 1;
            frq[s[i]-'a']++;
            if(frq[s[i]-'a'] == 3) {
               flag = 0;
            }
            if(flag) res+=s[i];
        }
    
        while(r < s.size()) {
         
            int flag = 1;
            frq[s[r]-'a']+=1;
            frq[s[l]-'a']-=1;
            if(frq[s[r]-'a'] == 3) {
               flag = 0;
            }
            if(flag) res+=s[r];
            l++;
            r++;
        }
        
        return res;
    }
};