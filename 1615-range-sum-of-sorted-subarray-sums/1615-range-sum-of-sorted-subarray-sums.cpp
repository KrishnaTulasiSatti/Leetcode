class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>sums;
        const int mod = 1e9+7;
        for(int i = 0 ; i < nums.size() ; i++) {
            int sum = 0;
            for(int j = i ; j < nums.size() ; j++) {
               sum = (sum % mod)+nums[j];
               sums.push_back(sum % mod);
            }
        }
        sort(sums.begin(),sums.end());
      //  for(auto it : sums) cout<<it<<" ";
        int rSum = 0;
        for(int i = left-1 ; i <= right-1 ; i++) {
            rSum = ((rSum % mod) + (sums[i] % mod) ) % mod;
        }
        return rSum;
    }
};