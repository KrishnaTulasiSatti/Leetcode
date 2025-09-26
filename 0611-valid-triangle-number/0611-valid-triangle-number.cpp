class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        

        sort(nums.begin(),nums.end());

        int cnt = 0;



        for(int i = 0 ; i < nums.size() ; i++) {

            if(nums[i] == 0) continue;

            for(int j = i+1 ; j < nums.size()-1 ; j++) {

                int sum = nums[i] + nums[j];

                int lb = lower_bound(nums.begin(),nums.end(),sum)-nums.begin();

                cnt += lb-j-1;

            }
        }

        return cnt;

    }
};