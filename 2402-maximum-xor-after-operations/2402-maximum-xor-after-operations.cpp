class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        int ind = 0;
        for(int i = 0 ; i < 32 ; i++) {
            int flag = 0;
            for(int j = 0 ; j < nums.size() ; j++) {
                if(nums[j] % 2 == 1) {
                    flag = 1;
                }
                nums[j] = nums[j] >> 1;
            }
            if(flag == 1) {
               ans+=(1 << ind);
            }
            ind++;
        }
        return ans;
    }
};