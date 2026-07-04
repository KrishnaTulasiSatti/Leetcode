class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {

        vector<int>frq(101,0);

        for(auto& it : nums) {
            frq[it]++;
        }

        int n = nums.size();

        int mid = nums[n/2];

        if(frq[mid] != 1) return false;
        return true;
    }
};