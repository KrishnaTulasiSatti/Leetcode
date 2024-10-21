class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>v(2,0);
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r < nums.size()) {
            v[nums[r]]++;
            if(nums[r] == 0) {
                while(v[nums[r]] > k) {
                  v[nums[l]]--;
                  l++;
                }
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};