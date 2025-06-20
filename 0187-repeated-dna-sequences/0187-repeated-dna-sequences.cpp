class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>m;

        string str = "";
        for(int i = 0 ; i < 10 ; i++) {
            str += s[i];
        }

        m[str]++;

        int i = 10;

        while(i < s.size()) {
            str += s[i];
            str = str.substr(1);
            m[str]++;
            i++;
        }

        vector<string>res;
        for(auto it : m) {
            if(it.second > 1) res.push_back(it.first);
        }

        return res;
    }
};