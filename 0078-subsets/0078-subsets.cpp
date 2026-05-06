class Solution {
public:

    vector<vector<int>>ans;

    void fun(vector<int>&nums,int i,int n,vector<int>&temp) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        fun(nums,i+1,n,temp);
        temp.pop_back();
        fun(nums,i+1,n,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        fun(nums,0,n,temp);
        return ans;
    }
};