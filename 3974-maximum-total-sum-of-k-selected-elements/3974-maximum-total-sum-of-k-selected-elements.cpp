class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        sort(nums.begin(),nums.end(),greater<int>());

        long long total = 0;

        int i = 0;

        while(k > 0 && mul > 0) {
            total += 1LL * nums[i++] * mul;
            k--;
            mul--;
        }   

        // cout << total << " " << k << " " << i << endl;

        while(k > 0) {
            total += nums[i++];
            k--;
        }

        return total;
    }
};