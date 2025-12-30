class Solution {
public:

    int fun1(vector<int>&nums,int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        unordered_map<int,int>m;

        int cnt = 0;

        while(r < n) {
            m[nums[r]]++;

            while(m.size() >= k) {
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }

            cnt += (r-l+1);
            r++;
        }

        return cnt;
    }

    int fun2(vector<int>&nums,int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        unordered_map<int,int>m;

        int cnt = 0;

        while(r < n) {
            m[nums[r]]++;

            while(m.size() > k) {
                cnt += (n-r);
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }

            r++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        int total = 1LL*n*(n+1)/2;

        int cnt1 = fun1(nums,k); // Subarrays less than k
        int cnt2 = fun2(nums,k); // Subarrays greater than k

        return total-cnt1-cnt2;
    }
};