class Solution {
public:
    int fun(vector<int>&cnt) {

        int res = 0;

        for(int i = 0 ; i < 32 ; i++) {
            if(cnt[i]) res += (1 << i);
        }

        return res;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int l = 0;
        int r = 0;

        int mini = INT_MAX;

        int x = 0;

        vector<int>cnt(32,0);

        while(r < nums.size()) {
            
            x |= nums[r];

            for(int i = 0 ; i < 32 ; i++) {
                if(nums[r] & (1 << i)) cnt[i]++;
            }

            while(x >= k && l <= r) {
                
                mini = min(mini,r-l+1);

                for(int i = 0 ; i < 32 ; i++) {
                    if(nums[l] & (1 << i)) cnt[i]--;
                }

                x = fun(cnt);
                l++;
            }

            r++;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};