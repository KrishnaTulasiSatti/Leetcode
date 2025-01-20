class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        set<pair<int,int>>s;

        for(int i = 0 ; i < k ; i++) {
            s.insert({nums[i],i});
        }

        res.push_back(s.rbegin()->first);

        for(int i = k ; i < nums.size() ; i++) {
            s.erase({nums[i-k],i-k});
            s.insert({nums[i],i});
            res.push_back(s.rbegin()->first);
        }
        return res;
    }
};