class Solution {
public:
bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>v(words.size(),0);
        for(int i = 0 ; i < words.size() ; i++) {
            string s = words[i];
            if(isVowel(s[0]) && isVowel(s[s.size()-1])) v[i] = 1;
        }

        vector<int>pref(words.size());
        pref[0] = v[0];
        for(int i = 1 ; i < v.size() ; i++) {
            pref[i] = pref[i-1]+v[i];
        }
        
        vector<int>res;
        for(int i = 0 ; i < queries.size() ; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int c = v[a] == 1 ? 1 : 0;
            if(a == 0) res.push_back(pref[b]);
            else if(a == b) res.push_back(v[b]);
            else res.push_back(pref[b]-pref[a]+c);
        }
        return res;
    }
};