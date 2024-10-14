class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>prefix(1000003,0);
        for(auto it : intervals) {
            int l = it[0];
            int r = it[1];
            prefix[l]+=1;
            prefix[r+1]-=1;
        }
        for(int i = 1 ; i < prefix.size() ; i++) {
            prefix[i] = prefix[i]+prefix[i-1];
        }
        int ans = *max_element(prefix.begin(),prefix.end());
        return ans;
    }
};