class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int>m;

        for(auto it : roads) {
            m[it[0]]++;
            m[it[1]]++;
        }

        vector<pair<int,int>> v;

        for(auto it : m) {
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());

        vector<int>cost(n);

        int c = n;

        for(auto it : v) {
            cost[it.second] = c;
            c--;
        }

        long long ans = 0;

        for(auto it : roads) {
            ans += (cost[it[0]]+cost[it[1]]);
        }

        return ans;
    }
};