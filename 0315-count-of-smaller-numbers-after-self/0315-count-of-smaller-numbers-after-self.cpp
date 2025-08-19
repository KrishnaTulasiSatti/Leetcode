class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size());
        ans[nums.size()-1] = 0;

        vector<int>v;
        v.push_back(nums[nums.size()-1]);

        for(int i = nums.size()-2 ; i >= 0 ; i--) {
            int idx = lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            ans[i] = idx;
            v.insert(v.begin()+idx,nums[i]);
        }

        return ans;

    }
};