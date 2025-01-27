class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt = 0;
        long long sum = 0;

        int l = 0;
        int r = 0;
        
        long long pro = 1;
        while(r < nums.size()) {
            sum+=nums[r];
            pro = sum*(r-l+1);

            while(pro >= k && l < nums.size()) {
                sum-=nums[l];
                l++;
                pro = sum*(r-l+1);
                
            }   
            if(sum < k ) cnt+=(r-l+1);
            r++;
        }
        return cnt;

        
    }
};