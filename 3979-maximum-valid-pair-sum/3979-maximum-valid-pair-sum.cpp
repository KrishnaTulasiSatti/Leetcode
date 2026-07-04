class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        
        int n = nums.size();

        int sum = 0;

        vector<int>suff(n,0);
        suff[n-1] = nums[n-1];

        for(int i = n-2 ; i >= 0 ; i--) {
            suff[i] = max(suff[i+1],nums[i]);
        }

        int res = 0;

        for(int i = 0 ; i < n-k ; i++) {
            res = max(res,nums[i]+suff[i+k]);
        }

        return res;
    }
};