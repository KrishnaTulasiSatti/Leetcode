class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones = 0 , twos = 0;

        for(int i = 0 ; i < nums.size() ; i++) {

            // If the number is not in twos then add it ones bucket
            // If the number is in ones bucket then delete it from ones and add it twos
            // If the number is not in ones bucket and is in twos bucket then delete it 
            // from twos bucket -- So that all 3 occurrences will be cancelled

            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }

        return ones;
    }
};