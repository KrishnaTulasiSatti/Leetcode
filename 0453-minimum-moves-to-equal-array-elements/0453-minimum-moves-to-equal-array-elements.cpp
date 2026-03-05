class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size();

        if(nums[0] == nums[n-1]) return 0;

        int ans = nums[n-1]-nums[0];

        for(int i = n-2 ; i > 0 ; i--) {
            nums[i] = nums[i] + ans;
            ans += nums[i] - nums[i+1];
        }

        return ans;
    }
};