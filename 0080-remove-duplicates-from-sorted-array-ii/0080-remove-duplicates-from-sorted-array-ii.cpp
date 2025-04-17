// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int k=1;
//         for(int i=1;i<nums.size();i++){
//             if(k==1 || nums[i] != nums[k-2]){
//                 nums[k++] = nums[i];
//             }
//         }
//         return k;
//     }
// };


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      
         int ind = 0;
         int ele = -1;
         int cnt = 0;

         for(int i = 0 ; i < nums.size() ; i++) {
          
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