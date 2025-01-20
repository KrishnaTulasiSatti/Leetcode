class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        vector<int>res(nums.size(),-1);
        if(nums.size() <= 2*k ) return res;

        long long sum = 0;
        for(int i = 0 ; i <= 2*k && i < nums.size(); i++) {
            sum+=nums[i];
        }
        cout<<sum<<endl;
        int j = k;
        res[j++] = sum/(2*k+1);

        for(int i = 2*k+1 ; i < nums.size() ; i++) {
            sum-=nums[i-(2*k+1)];
            sum+=nums[i];
            cout<<sum<<endl;
            res[j++] = sum/(2*k+1);
        }

        return res;
    }
};