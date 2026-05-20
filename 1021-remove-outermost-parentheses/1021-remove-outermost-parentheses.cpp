class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string res = "";

        int open = 0;
        
        for(int i = 0 ; i < s.size() ; i++) {

            if(s[i] == '(') {
                open++;
                if(open > 1) res += '(';
            }
            else {
                open--;
                if(open > 0) res += ')';
            }
        }

        return res;
    }
};