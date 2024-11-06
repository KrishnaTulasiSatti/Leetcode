class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++) {
            for(int j = 0 ; j < nums.size()-1 ; j++) {
                int x = __builtin_popcount(nums[j]);
                int y = __builtin_popcount(nums[j+1]);
                if(nums[j] > nums[j+1]) {
                    if(x != y) return false;
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        return true;
    }
};