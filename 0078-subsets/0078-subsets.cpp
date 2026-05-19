class Solution {
public:

    vector<vector<int>>ans;

    void fun(int i,int n,vector<int>&temp,vector<int>&nums) {
        
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        fun(i+1,n,temp,nums);
        temp.pop_back();

        fun(i+1,n,temp,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>temp;
        int n = nums.size();

        fun(0,n,temp,nums);
        return ans;

    }
};