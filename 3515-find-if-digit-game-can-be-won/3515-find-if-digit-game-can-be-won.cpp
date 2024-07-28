class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0;
        int doublee = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < 10) single+=nums[i];
            else doublee+=nums[i];
        }
        if(single == doublee) return false;
        return true;
    }
};