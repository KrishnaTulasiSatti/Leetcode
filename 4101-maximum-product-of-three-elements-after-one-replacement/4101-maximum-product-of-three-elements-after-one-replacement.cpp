class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        
        long long res = 1;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < 0) nums[i] = -1*nums[i];
        }

        sort(nums.begin(),nums.end());

        int n = nums.size();

        long long a = nums[n-1];
        long long b = nums[n-2];

        long long c = 100000;

        res = 1LL*a*b*c;

        return res;

        
    }
};