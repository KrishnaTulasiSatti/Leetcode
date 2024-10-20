class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int>m;
        while(r < n) {
           m[nums[r]]++;
           while(m[nums[r]] > k) {
             m[nums[l]]--;
             l++;
           }
           maxi = max(maxi,(r-l)+1);
           r++;
        }
        return maxi;
    }
};