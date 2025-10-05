class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int total_xor = 0;

        long long sum = 0;
        
        for(auto it : nums) {
            total_xor ^= it;
            sum += it;
        }

        if(total_xor) return nums.size();

        if(sum == 0) return 0;

        return nums.size()-1;
    }
};