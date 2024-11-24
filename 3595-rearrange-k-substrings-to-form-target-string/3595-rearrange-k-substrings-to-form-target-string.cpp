class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int d = s.size()/k;
        unordered_map<string,int>m1;
        string str = "";
        for(int  i = 0 ; i < s.size() ; i++) {
            if((i+1) % d == 0) {
                str+=s[i];
                m1[str]+=1;
                str = "";
            }
            else str+=s[i];
        }
        unordered_map<string,int>m2;
        str = "";
        for(int  i = 0 ; i < t.size() ; i++) {
            if((i+1) % d == 0) {
                str+=t[i];
                m2[str]+=1;
                str = "";
            }
            else str+=t[i];
        }
        for(auto it : m1) {
            string st = it.first;
            if(m1[st] != m2[st]) return false;
        }
        for(auto it : m2) {
            string st = it.first;
            if(m1[st] != m2[st]) return false;
        }
        return true;
    }
};