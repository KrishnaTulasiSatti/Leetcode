class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string,int>m;

        string str;

        vector<string>res;

        for(int i = 0 ; i < s.size() ; i++) {
            str += s[i];
            if(m[str] > 0) {
                continue;
            }
            else {
                res.push_back(str);
                m[str]++;
                str = "";
            }
        }

        return res;
    }
};