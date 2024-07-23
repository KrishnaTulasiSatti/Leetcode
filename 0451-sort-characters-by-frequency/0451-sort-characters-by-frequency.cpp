class Solution {
public:
static bool cmp(const pair<char,int>&a , const pair<char,int>&b) {
    return a.second > b.second;
}
    string frequencySort(string s) {
        map<char,int>m;
        for(int i = 0 ; i < s.size() ; i++) m[s[i]]++;
        vector<pair<char,int>>vec(m.begin(),m.end());
        sort(vec.begin(),vec.end(),cmp);
        string res = "";
        for(auto it : vec) {
            for(int i = 0 ; i < it.second ; i++) {
                res+=it.first;
            }
        }
        return res;
    }
};