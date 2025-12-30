class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int cnt = 0;

        int l = 0;
        int r = 0;
        
        int maxi = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) cnt++;

            while(cnt > k) {
                if(nums[l] == 0) cnt--;
                l++;
            }

            cout << l << " " << r << endl;

            maxi = max(maxi,r-l+1);
            r++;

        }

        return maxi;
    }
};