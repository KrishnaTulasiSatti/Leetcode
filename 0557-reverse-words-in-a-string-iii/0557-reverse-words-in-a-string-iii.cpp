class Solution {
public:
    string reverseWords(string s) {
        string part = "";
        string res;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != ' ') part+=s[i];
            else {
                reverse(part.begin(),part.end());
                res+=part;
                res+=s[i];
                part = "";
            }
        }
        reverse(part.begin(),part.end());
        res+=part;
        return res;
    }
};