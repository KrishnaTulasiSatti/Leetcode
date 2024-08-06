class Solution {
public:
static bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
    return a.second > b.second;
}
    int minimumPushes(string word) {
        unordered_map<char,int>m;
        for(int i = 0 ; i < word.size() ; i++) m[word[i]]++;
     //   for(auto it : m) cout<<it.first<<"-->"<<it.second<<endl;
        vector<pair<char,int>>v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        // for(auto it : v) {
        //     cout<<it.first<<"-->"<<it.second<<endl;
        // }
        int c = 1;
        int cnt = 0;
        for(auto it : v) {
           int n = c/8;
           if(c % 8) n++;
           cnt+=(it.second*n);
           c++;

        }
        return cnt;
    }
};