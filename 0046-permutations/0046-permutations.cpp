class Solution {
public:
vector<vector<int>>res;

void fun(vector<int>&nums,vector<int>&vis,int ind,int n,vector<int>&temp) {

    if(temp.size() == n) {
        res.push_back(temp);
        return;
    }

    for(int i = 0 ; i < nums.size() ; i++) {
        if(vis[i] == 0) {
            temp.push_back(nums[i]);
            vis[i] = 1;
            fun(nums,vis,i+1,n,temp);
            temp.pop_back();
            vis[i] = 0;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        vector<int>temp;

        fun(nums,vis,0,nums.size(),temp);

        return res;
    }
};