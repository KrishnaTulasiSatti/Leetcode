class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i = 0 ; i+k <= nums.size() ; i++) {
            int c = 0;
            int flag = 1;
            for(int j = i+1 ; c < k-1 ; j++){
                if(nums[j-1] != nums[j]-1) {
                    flag = 0;
                    //cout<<nums[j-1]<<" "<<nums[j]<<" ";
                    break;
                }
                c++;
            }
            if(flag) ans.push_back(nums[i+k-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};