class Solution {
public:
int atMostSubarrays(vector<int>& nums,int k) {
     int ans = 0;
        int oddCount = 0;
        int l = 0;
        int r = 0;
        while(r < nums.size()) {
            if(nums[r] % 2) oddCount++;

         while(oddCount > k) {
            if(nums[l] % 2) oddCount--;
            l++;

        }
          ans+=(r-l+1);
          r++;
        }
        return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atMostSubarrays(nums,k)-atMostSubarrays(nums,k-1);
    }
};