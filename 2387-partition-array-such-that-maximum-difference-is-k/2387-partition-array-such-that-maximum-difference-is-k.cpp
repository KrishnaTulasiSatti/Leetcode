class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int cnt = 0;
        int mini = nums[0];
        
        int i = 1;
        while(i < nums.size()) {

            int maxi = nums[i];
            if(abs(mini-maxi) <= k) {
                i++;
            }
            else {
                cnt++;
                mini = nums[i];
            }

        }
        return cnt+1;
    }
};