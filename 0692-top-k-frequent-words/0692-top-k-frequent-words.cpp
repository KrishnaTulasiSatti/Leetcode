class Solution {
public:
static bool cmp(const pair<string,int>&a,const pair<string,int>&b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(int i = 0 ; i < words.size() ; i++) {
            m[words[i]]++;
        }
        vector<pair<string,int>>v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        vector<string>res;
        for(int i = 0 ; i < k ; i++) res.push_back(v[i].first);
        return res;
    }
};