class Solution {
public:
vector<vector<int>>ans;

void fun(vector<int>&nums,vector<int>&temp,int ind,int n) {
    ans.push_back(temp);

    for(int i = ind ; i < n ; i++) {
        if(i != ind && nums[i] == nums[i-1]) continue;

        temp.push_back(nums[i]);
        fun(nums,temp,i+1,n);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        fun(nums,temp,0,nums.size());

        return ans;
    }
};