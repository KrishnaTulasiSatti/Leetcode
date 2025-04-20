class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cnt = 0;

        int maxi = 0;
      
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] >= maxi) {
                cnt++;
                maxi = nums[i];
                
            } 
        }
        
        return cnt;
    }
};