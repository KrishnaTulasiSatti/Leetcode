class Solution {
public:

int count(vector<int>&nums,int x) {

    int cnt = 0;

    for(int i = 0 ; i < nums.size()-1 ; i++) {

        int diff = abs(nums[i]-nums[i+1]);

        if(diff <= x) {
            cnt++;
            i++;
        }
    }

    return cnt;
}
    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(),nums.end());
        
        int low = 0;
        int high = 1e9;

        int ans = -1;

        while(low <= high) {

            int mid = (low+high)/2;

            // Cnt the pairs with the diff <= mid;

            int cnt = count(nums,mid);

            if(cnt >= p) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;


        }

        return ans;
    }
};