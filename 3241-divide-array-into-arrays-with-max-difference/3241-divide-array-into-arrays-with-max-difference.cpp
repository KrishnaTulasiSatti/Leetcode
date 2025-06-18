class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        
        vector<vector<int>>res;

        vector<int>temp;

        for(int i = 0 ; i < nums.size()-2 ; ) {
            if(abs(nums[i]-nums[i+2]) <= k) {
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                res.push_back(temp);
                temp = {};
                i+=3;
            }
            else return {};
            
        }
        return res;
    }
};