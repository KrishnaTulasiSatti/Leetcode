class Solution {
public:
    string removeOccurrences(string s, string part) {

        string res = "";

        for(int i = 0 ; i < s.size() ; i++) {

            res += s[i];

            if(res.size() < part.size()) continue;

            int ind = res.size()-part.size();
            string sub = res.substr(ind);
            
            if(sub == part) res = res.substr(0,ind);

        }
        return res;

    }
};