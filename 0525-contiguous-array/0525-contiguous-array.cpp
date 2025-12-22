class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int>m;

        int val = 0;

        int maxi = 0;

        m[0] = -1;

        for(int i = 0 ; i < nums.size() ; i++) {

            if(nums[i] == 0) val++;
            else val--;

            int req = val;

            if(m.find(req) != m.end()) maxi = max(maxi,i-m[val]);

            if(m.find(val) == m.end()) m[val] = i;
        }

        return maxi;
    }
};