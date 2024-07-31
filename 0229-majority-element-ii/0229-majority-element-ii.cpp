class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       //Boyer-Moore voting Algorithm --> An optimal approach
       int ele1 = INT_MIN,ele2 = INT_MIN;
       int count1 = 0,count2 = 0;
       for(int i = 0 ; i < nums.size() ; i++){
           if(count1 == 0 && nums[i] != ele2){
               count1 = 1;
               ele1 = nums[i];
           }
           else if(count2 == 0 && nums[i] != ele1){
               count2 = 1;
               ele2 = nums[i];
           }
           else if(nums[i] == ele1) count1++;
           else if(nums[i] == ele2) count2++;
           else {
               count1--;
               count2--;
           }
       }
       int c1 = 0,c2 = 0;
       vector<int>res;
       for(int i = 0 ; i < nums.size() ; i++){
              if(nums[i] == ele1) c1++;
              if(nums[i] == ele2) c2++;
       }
       if(c1 > nums.size()/3) res.push_back(ele1);
       if(c2 > nums.size()/3) res.push_back(ele2);
       return res;

    }
};