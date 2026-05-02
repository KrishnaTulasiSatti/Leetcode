class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>res;

        res.push_back(nums[0]);

        for(int i = 1 ; i < nums.size() ; i++) {
            if(res.back() < nums[i]) res.push_back(nums[i]);
            else {
                int lb = lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[lb] = nums[i];
            }
        }

        return res.size();
    }
};