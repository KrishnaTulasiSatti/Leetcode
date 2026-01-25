class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        
        int ind = 0;

        for(int i = nums.size()-1 ; i > 0 ; i--) {
            if(nums[i] <= nums[i-1]) {
                ind = i;
                break;
            }
        }

        return ind;


    }
};