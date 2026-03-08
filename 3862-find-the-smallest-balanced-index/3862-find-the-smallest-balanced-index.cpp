class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        int sum = 0;
        int n = nums.size();
        vector<long long>pro(n,1);

        const int mod = 1e9+7;
        
        for(int i = n-2 ; i >= 0 ; i--) {
            pro[i] = (1LL * pro[i+1] * nums[i+1]) % mod;
        }

        for(int i = 0 ; i < n ; i++) {
            if(sum == pro[i]) return i;
            sum += nums[i];

            sum %= mod;
        }

        return -1;
    }
};