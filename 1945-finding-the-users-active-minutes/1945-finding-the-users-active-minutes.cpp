class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
       map<int,set<int>>m;
       for(int i = 0 ; i < logs.size() ; i++) {
          int u = logs[i][0];
          int t = logs[i][1];
          m[u].insert(t);
       }


       vector<int>res(k,0);
       for(auto it : m) {
          int s = it.second.size();
          res[s-1]++;
       } 
       return res;

    }
};