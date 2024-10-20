class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(),nums.end());
        long long cnt = 0;
        int l = 0;
        int r = 0;
        long long ans = 0;
        int n = nums.size();
        while(r < nums.size()) {
            if(nums[r] == max) cnt++;
            while(cnt >= k) {
                if(nums[l] == max) cnt--;
                l++;
            } 
            ans+=(r-l)+1;
            r++;
        }
        long long res = ((long long)n*(long long)(n+1))/2;
        return res-ans;
    }
};