class Solution {
public:
    int fun(string& s,char ch) {

        int cnt = 0;
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == ch) {
                ch = (s[i] == '0') ? '1' : '0';
                cnt++;
            }
            else ch = s[i];
           // cout << ch << endl;
        }

        return cnt;
    }
    int minOperations(string s) {
        
        return min(fun(s,'0'),fun(s,'1'));
    }
};