class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int inc1 = 0;
        int dec = 0;
        int inc2 = 0;

        for(int i = 0 ; i < nums.size()-1 ; i++) {
            
            if(nums[i] < nums[i+1]) {
                if(inc1 == 1 && dec == 1) inc2 = 1;
                else if(dec == 0) inc1 = 1;
                else return false; 
            }
            else {
                if(inc1 == 1) dec = 1;
                if(inc2 == 1 || inc1 == 0) return false;
            }

            if(nums[i] == nums[i+1]) return false;
        }

        if(inc1 && dec && inc2) return true;
        return false;
    }
};