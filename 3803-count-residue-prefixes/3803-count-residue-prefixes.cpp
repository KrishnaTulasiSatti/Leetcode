class Solution {
public:
    int residuePrefixes(string s) {

        unordered_map<char,int>m;

        int cnt = 0;

        for(int i = 0 ; i < s.size() ; i++) {
            m[s[i]]++;

            if((i+1) % 3 == m.size()) cnt++;
        }

        return cnt;
    }
};