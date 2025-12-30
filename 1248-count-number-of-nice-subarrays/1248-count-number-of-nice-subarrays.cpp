class Solution {
public:

    int funLessK(vector<int>&nums,int k) {

        int l = 0;
        int r = 0;

        int cnt = 0;
        int odd = 0;

        while(r < nums.size()) {
            if(nums[r] % 2) odd++;

            while(odd >= k) {
                if(nums[l] % 2) odd--;
                l++;
            }

            cnt += (r-l+1);
            r++;
        }

        return cnt;

    }

    int funGreaterK(vector<int>&nums,int k) {

        int n = nums.size();

        int l = 0;
        int r = 0;

        int cnt = 0;
        int odd = 0;

        while(r < nums.size()) {
            if(nums[r] % 2) odd++;

            while(odd > k) {
                cnt += n-r;
                if(nums[l] % 2) odd--;
                l++;
            }

            r++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long total = 1LL*n*(n+1)/2;

        int cnt1 = funLessK(nums,k);
        int cnt2 = funGreaterK(nums,k);

        cout << cnt1 << " " << cnt2 << endl;

        return total-cnt1-cnt2;
    }
};