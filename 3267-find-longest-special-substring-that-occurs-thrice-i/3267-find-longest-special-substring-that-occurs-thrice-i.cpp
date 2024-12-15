class Solution {
public:
    int maximumLength(string s) {
        vector<string>v;
        for(int i = 0 ; i < s.size() ; i++) {
            char ch = s[i];
            string str = "";
            str+=ch;
            v.push_back(str);
            for(int j = i+1 ; j < s.size() ; j++) {
                if(s[i] == s[j]) {
                    str+=s[j];
                    v.push_back(str);
                }
                else break;
            }
        }
        unordered_map<string,int>m;
        for(auto it : v) {
            m[it]+=1;
        }
        int maxi = -1;
        string res = "";
        for(auto it : m) {
           if(it.second >= 3 && it.first.size() > res.size()) {
            maxi = it.second;
            res = it.first;
           }
        }
        cout<<res<<endl;
        if(maxi >= 3) return res.size();
        return -1;
    }
};