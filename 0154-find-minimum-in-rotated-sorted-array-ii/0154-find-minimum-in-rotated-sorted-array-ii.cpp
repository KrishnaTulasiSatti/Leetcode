class Solution {
public:
    int findMin(vector<int>& nums) {

        // WE have to handle one edge case nums[low] == nums[mid] == nums[high]


        int low = 0;
        int high = nums.size()-1;

        int mini = INT_MAX;

        while(low <= high) {
            int mid = (low+high)/2;

            // Edge case

            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                mini = min(mini,nums[mid]);
                low++;
                high--;
                continue;
            }

            // if left part is sorted

            if(nums[low] <= nums[mid]) {
                mini = min(mini,nums[low]);
                low = mid+1;
            }
            else {
                // right part is sorted
                mini = min(nums[mid],mini);
                high = mid-1;
            }
        }
        return mini;
    }
};