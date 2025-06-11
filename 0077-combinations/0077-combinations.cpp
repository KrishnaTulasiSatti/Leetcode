class Solution {
public:

vector<vector<int>>ans;

void fun(vector<int>&nums,int i,int n,int k,vector<int>&temp) {

    if(i == n) {
        int length = temp.size();

        if(length == k) {
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(nums[i]);
    fun(nums,i+1,n,k,temp);
    temp.pop_back();

    fun(nums,i+1,n,k,temp);

}
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i = 1 ; i <= n ; i++) {
            nums.push_back(i);
        }

        // Pick the subsets of length k

        vector<int>temp;

        fun(nums,0,nums.size(),k,temp);

        return ans;
    }
};