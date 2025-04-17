class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = -1;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(cnt == 0) {
                candidate = nums[i];
                cnt = 1;
            }
            else if(candidate == nums[i]) cnt++;
            else cnt--;
        }

        cnt = 0;
        for(auto it : nums) {
            if(it == candidate) cnt++;
        }

        if(cnt > nums.size()/2) return candidate;
        return -1;
    }
};