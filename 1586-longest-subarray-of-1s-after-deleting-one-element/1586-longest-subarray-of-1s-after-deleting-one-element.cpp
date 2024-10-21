class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxi = 0;
        vector<int>v(2,0);
        while(r < n) {
            v[nums[r]]++;
            if(nums[r] == 0) {
                while(v[nums[r]] > 1) {
                    v[nums[l]]--;
                    l++;
                }
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi-1;
    }
};