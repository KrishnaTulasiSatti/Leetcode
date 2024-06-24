class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int k = 0;
        for(int i = 0 ; i < words.size() && k < s.size() ; i++) {
            string str = words[i];
            for(int j = 0 ; j < str.size() ; j++) {
               if(str[j] != s[k]) return false;
               k++;
            }
        }
        if(k == s.size()) return true;
        return false;
    }
};