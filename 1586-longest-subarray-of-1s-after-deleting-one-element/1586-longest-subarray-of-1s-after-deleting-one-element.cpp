class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;

        int z = 0;
        int maxi = 0;
        while(r < nums.size()) {
            if(nums[r] == 0) z++;

            while(z > 1 && l < nums.size()) {
                if(nums[l] == 0) z--;
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }

        return maxi-1;

    }
};