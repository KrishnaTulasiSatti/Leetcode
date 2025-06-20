class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // This is similar to the question
        // Finding the cycle in linked list where they intersect

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];  // 1 step
            fast = nums[nums[fast]]; // 2 steps
        }while(slow != fast);

        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};