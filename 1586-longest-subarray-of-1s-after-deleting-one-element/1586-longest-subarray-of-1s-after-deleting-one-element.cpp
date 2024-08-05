class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int zeros = 0;
        int maxi = 0;
        while(r < nums.size()) {
           if(nums[r] == 0) zeros++;
           while(zeros > 1) {
             if(nums[l] == 0) zeros--;
             l++;
           }
           if(zeros <= 1) maxi = max(maxi,r-l);
           r++;
        }
        if(maxi == 0) return 0;
        return maxi;
    }
};