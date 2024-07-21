class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelsCount = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
              vowelsCount++;
        }
        if(vowelsCount == 0) return false;
        return true;
    }
};