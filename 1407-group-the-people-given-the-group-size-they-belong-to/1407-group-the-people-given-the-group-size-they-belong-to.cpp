class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>res;
        multimap<int,int>m;
        for(int i = 0 ; i < groupSizes.size() ; i++) {
           m.insert(pair<int,int>(groupSizes[i],i));
        }
        for(auto it = m.begin() ; it != m.end() ; ) {
            int k = it->first;
            vector<int>ans;
            while(k) {
                ans.push_back(it->second);
                it++;
                k--;
            }
            res.push_back(ans);
        }
        return res;
    }
};