class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zc = 0;
        int product = 1;
        int pos = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0) {
                zc++;
                pos = i;
            }
            else{
                product*=nums[i];
            }
        }
        vector<int>res;
        if(zc > 1){
            for(int i = 0 ; i < nums.size() ; i++) res.push_back(0);
        }
        else{
        for(int i = 0 ; i < nums.size() ; i++){
            if(zc == 1){
                if(i != pos)  res.push_back(0);
                else res.push_back(product);
            }
            else res.push_back(product/nums[i]);
           }
        }
        return res;
    }
};