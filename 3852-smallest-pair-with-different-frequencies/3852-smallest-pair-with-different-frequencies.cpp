class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        map<int,int>m;

        for(auto it : nums) m[it]++;

        vector<int>res;

        sort(nums.begin(),nums.end());

        int x = m[nums[0]];

        for(auto it : m) {
            if(it.second != x) {
                res.push_back(nums[0]);
                res.push_back(it.first);
                break;
            }
        } 

        if(res.size() != 0) return res;
        return {-1,-1};
    }
};