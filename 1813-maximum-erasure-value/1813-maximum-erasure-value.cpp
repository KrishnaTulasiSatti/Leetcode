class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi = 0;
        int sum = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int>m;
        while(r < n) {
            m[nums[r]]++;
            sum+=nums[r];
            while(m[nums[r]] > 1) {
                m[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            maxi = max(sum,maxi);
            r++;


        }
       return maxi;
    }
};