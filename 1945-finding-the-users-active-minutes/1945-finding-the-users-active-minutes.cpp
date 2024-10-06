class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>>m;
        for(auto it : logs) {
            m[it[0]].insert(it[1]);
        }
        vector<int>res(k,0);
        unordered_map<int,int>m2;
        for(auto it : m) {
            m2[it.second.size()]++;
        }
        for(auto it : m2) {
            //cout<<it.first<<" "<<it.second<<endl;
            res[it.first-1] = it.second;
        }
        return res;
    }
};