class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        

        sort(nums.begin(),nums.end());

        long long cnt = 0;
 
        for(int i = 0 ; i < nums.size() ; i++) {
            long long rtarget = upper-nums[i];
            long long ltarget = lower-nums[i];
            
            int lind = -1;
            int rind = -1;
        
            lind = lower_bound(nums.begin()+i+1,nums.end(),ltarget)-nums.begin();
            rind = upper_bound(nums.begin()+i+1,nums.end(),rtarget)-nums.begin()-1;
            
            cout << ltarget << " " << rtarget << " ";
           // cout << lind << " " << rind << endl;

            if(lind >= 0 && rind < nums.size()) {
                cout << lind << " " << rind << endl;
                cnt += (rind-lind+1);
            }

            
        }
        return cnt;
    }
};