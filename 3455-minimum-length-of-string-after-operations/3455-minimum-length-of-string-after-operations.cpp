class Solution {
public:
    int minimumLength(string s) {
        int frqleft[26] = {0};
        int frqright[26] = {0};
        for(int i = 0 ; i < s.size() ; i++) {
            frqright[s[i]-'a']++;
        }
        frqleft[s[0]-'a']++;
        int len = s.size();
        frqright[s[0]-'a']--;
        for(int i = 1 ; i < s.size()-1 ; i++) {
            frqright[s[i]-'a']--;
            if(frqleft[s[i]-'a'] > 0 && frqright[s[i]-'a'] > 0) {
                len-=2;
                frqleft[s[i]-'a']--;
                frqright[s[i]-'a']--;
            } 
             frqleft[s[i]-'a']++;

        }
        return len;
    }
};