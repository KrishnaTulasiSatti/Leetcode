class Solution {
public:

    vector<vector<int>>ans;

    void fun(vector<int>& nums,int i,vector<int>& temp,int n,int k) {

        if(i == 9) {
            if(temp.size() == k) {
                if(n == 0) ans.push_back(temp);
            }
            return;
        }

        if(n < 0 || temp.size() > k) return;

        temp.push_back(nums[i]);
        fun(nums,i+1,temp,n-nums[i],k);
        temp.pop_back();

        fun(nums,i+1,temp,n,k);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>nums = {1,2,3,4,5,6,7,8,9};

        vector<int>temp;

        fun(nums,0,temp,n,k);

        return ans;


    }
};