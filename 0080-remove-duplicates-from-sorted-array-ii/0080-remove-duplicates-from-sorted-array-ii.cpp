class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      
         int ind = 0;
         int ele = -1;
         int cnt = 0;

         for(int i = 0 ; i < nums.size() ; i++) {
           // cout << nums[i] << " " << ele << " " << cnt << endl;
            if((nums[i] == ele && cnt < 2)) {
                nums[ind++] = nums[i];
                cnt++;
                ele = nums[i];
            }
            else if(nums[i] != ele) {
                cnt = 0;
                nums[ind++] = nums[i];
                cnt++;
                ele = nums[i];
            }
            
         }
         return ind;
    }
};