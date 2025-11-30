class Solution {
public:
    int countElements(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int cnt = 0;

        for(int i = 0 ; i < nums.size() ; i++) {

            int ub = upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();

            int c = nums.size()-ub;

            if(c >= k) cnt++;
        }

        return cnt;

        
    }
};