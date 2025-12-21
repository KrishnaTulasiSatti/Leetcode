class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        
        unordered_map<char,long long>m;

        long long totalCost = 0;
        
        for(int i = 0 ; i < s.size() ; i++) {
            m[s[i]] += cost[i];
            totalCost += (1LL*cost[i]);
        }

        long long mini;

        for(auto it : m) {
            mini = min(mini,totalCost-it.second);
        }

        return mini;
    }
};