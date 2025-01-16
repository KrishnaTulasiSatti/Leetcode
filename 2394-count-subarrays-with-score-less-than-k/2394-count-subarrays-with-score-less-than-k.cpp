class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long score = 0;
        long long sum = 0;
        long long l = 0;
        long long r = 0;
        long long cnt = 0;
        while(r < nums.size()) {
            sum+=nums[r];
          
            while(sum >= k*1.0/(r-l+1) && l < nums.size()) {
                sum-=nums[l];
                l++;

                
            } 
           // cout<<r<<" "<<l<<endl;
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};