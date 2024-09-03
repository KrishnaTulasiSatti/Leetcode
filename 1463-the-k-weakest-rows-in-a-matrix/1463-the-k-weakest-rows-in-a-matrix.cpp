class Solution {
public:

   static bool cmp(const pair<int,int>&a,const pair<int,int>&b) {
       if(a.second == b.second) return a.first < b.first;
       return a.second < b.second;
   }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>v;
        for(int i = 0 ; i < mat.size() ; i++) {
            int sum = 0;
            for(int j = 0 ; j < mat[i].size() ; j++) sum+=mat[i][j];
            v.push_back({i,sum});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>res;
        int i = 0;
        while(k--) {
            res.push_back(v[i].first);
            i++;
        }
        return res;
    }
};