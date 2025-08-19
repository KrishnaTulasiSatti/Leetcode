class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;

        int r = 0;

        long long zc = 0;



        while(r < nums.size()) {
            if(nums[r] != 0) {
                cnt += (zc*(zc+1)/2);
                zc = 0;
            }
            else zc++;
            r++;
        }
        cnt += (zc*(zc+1)/2);
        return cnt;

    }
};