class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++) {
            int flag = false;
            for(int j = 0 ; j < nums.size()-i-1 ; j++) {
                if(nums[j] > nums[j+1]) {
                    flag = true;
                    swap(nums[j],nums[j+1]);
                }
            }
            if(flag == false) break;
        }
    }
};