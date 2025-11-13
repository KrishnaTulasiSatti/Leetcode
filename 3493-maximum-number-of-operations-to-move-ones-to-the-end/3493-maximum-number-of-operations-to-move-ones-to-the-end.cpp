class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0;

        int ones = 0;

        if(s[0] == '1') ones++;

        for(int i = 1 ; i < s.size() ; i++) {

            if(s[i] == '1' && s[i-1] == '0') {
                cnt += ones;
            }

            if(s[i] == '1') ones++;
        }

        if(s[s.size()-1] == '0') cnt += ones;


        return cnt;
    }
};