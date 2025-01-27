class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int l = 0;
        int r = k;
        multiset<int>s;
        for(int i = 0 ; i < k ; i++) {
            s.insert(nums[i]);
        } 
        res.push_back(*s.rbegin());
        while(r < nums.size()) {
            s.insert(nums[r]);
            s.erase(s.find(nums[l]));
            res.push_back(*s.rbegin());
            l++;
            r++;
        }
        return res;

    }
};