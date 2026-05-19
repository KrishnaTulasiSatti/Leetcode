class Solution {
public:

    set<vector<int>>ans;

    void fun(int i,int n,vector<int>&temp,vector<int>&nums) {
        
        if(i == n) {
            ans.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        fun(i+1,n,temp,nums);
        temp.pop_back();

        fun(i+1,n,temp,nums);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        
        fun(0,n,temp,nums);

        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};