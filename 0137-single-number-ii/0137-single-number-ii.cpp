class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        long long num = 0;

        for(int i = 0 ; i < 32 ; i++) {

            int cnt = 0;

            for(int j = 0 ; j < nums.size() ; j++) {
                if(nums[j] & 1) cnt++;
                nums[j] = nums[j] >> 1;
            }

            if(cnt % 3) {
                num += pow(2,i);
            }
        }

        return num;



    }
};