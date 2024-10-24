class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       if(s.size() < 10) return {};
       string str;
       for(int i = 0 ; i < 10 ; i++) str+=s[i];
       int l = 0;
       int r = 10;
      
       unordered_map<string,int>m;
       m[str]++;
       while(r < s.size()) {
          
          str.erase(str.begin());
          str+=s[r];
          m[str]++;
          r++;
          l++;
       }
       vector<string>res;
       for(auto it : m) {
        if(it.second > 1) res.push_back(it.first);
       }
       return res;
    }
};