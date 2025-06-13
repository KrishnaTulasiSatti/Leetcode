class Solution {
public:

int fun(vector<int>&nums,int ind,int n,vector<int>&dp) {

    if(ind >= n) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    // Pick the element and move to the next next index

    int pick = nums[ind]+fun(nums,ind+2,n,dp);

    // Not Pick the element

    int non_pick = fun(nums,ind+1,n,dp);

    return dp[ind] = max(pick,non_pick);
}
    int rob(vector<int>& nums) {
           
   if(nums.size() == 1) return nums[0];

    int n = nums.size();
    
    vector<int>temp1;
    for(int i = 0 ; i < n-1 ; i++) {
        temp1.push_back(nums[i]);
    }

    vector<int>temp2;
    for(int i = 1 ; i < n ; i++) {
        temp2.push_back(nums[i]);
    }
    
    vector<int> dp1(temp1.size(), -1);
    vector<int> dp2(temp2.size(), -1);

    int a = fun(temp1,0,temp1.size(),dp1);

    int b = fun(temp2,0,temp2.size(),dp2);

    return max(a,b);

     
    }
};