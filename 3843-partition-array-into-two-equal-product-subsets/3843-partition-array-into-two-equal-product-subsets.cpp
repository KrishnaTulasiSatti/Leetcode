typedef __int128 ll;
class Solution {
public:
    bool find(vector<int>&nums,ll target) {

        int n = nums.size();

        for(int i = 0 ; i < (1 << n) ; i++) {
            ll sum = 1;
            for(int j = 0 ; j < n ; j++) {
            if(i & (1 << j)) {
                sum *= nums[j];
                if(sum == target) return true;
            }
        }
    }
    
    return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll totalSum = 1;

        for(int i = 0 ; i < nums.size() ; i++) {
            
            totalSum = (totalSum*nums[i]);
            //if (totalSum > (ll)target*target) return false; 
        }

        bool f1 = find(nums,target);
        if(f1 == false) return false;
        ll rem = totalSum/target;
        if(rem == target) return true;
        return false;
    }
};