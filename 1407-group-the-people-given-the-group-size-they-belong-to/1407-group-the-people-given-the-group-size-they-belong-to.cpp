class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       multimap<int,int>m;
       for(int i = 0 ; i < groupSizes.size() ; i++) {
          m.insert(pair<int,int>(groupSizes[i],i));
       }
       vector<vector<int>>ans;
       int prev = 0;
       vector<int>v;
      // for(auto it : m) cout<<it.first<<" "<<it.second;
       for(auto it : m) {
         if(it.first != prev) {
            v = {};
            v.push_back(it.second);
            prev = it.first;
         }
         else {
            v.push_back(it.second);
         }
         if(v.size() == it.first) {
                ans.push_back(v);
                v = {};
            }
       }
       return ans;
    }
};