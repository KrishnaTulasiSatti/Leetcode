class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9+7;

        for(int i = 0 ; i < queries.size() ; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;
            while(idx <= r && idx <= nums.size()) {
                nums[idx] =(1LL*(nums[idx] % mod) *(v % mod)) % mod;
                idx += k;
            }
        }

        int xr = 0;
        for(auto it : nums) {
            xr = xr ^ it;
        }
        return xr;
    }
};