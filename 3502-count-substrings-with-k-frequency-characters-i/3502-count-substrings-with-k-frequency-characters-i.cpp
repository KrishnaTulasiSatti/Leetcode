class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            unordered_map<char,int>m;
            int flag = 0;
            for(int j = i ; j < s.size() ; j++) {
                m[s[j]]++;
                if(m[s[j]] >= k) flag = 1;
                if(flag) cnt++;

            }
        }
        return cnt;
    }
};