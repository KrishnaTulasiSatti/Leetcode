class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(),nums.end(),0);

        int cnt = 0;

        for(int i = 0 ; i < nums.size()-1 ; i++) {
            totalSum -= nums[i];
            double avg = totalSum/(nums.size()-1-i);
            if(nums[i] > avg) cnt++;
        }

        return cnt;
    }
};