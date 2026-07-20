class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {

        int cnt = 0;

        int ans = 0;

        const int mod = 1e9 + 7;
        
        for(int i = 0 ; i < nums.size() ; i++) {
            
            if(nums[i] < a) ans = (ans + cnt) % mod;

            if(nums[i] >= a) cnt++;
        }

        // ans += cnt;

        vector<int>temp;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < a) temp.push_back(nums[i]);
        }

        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] >= a) temp.push_back(nums[i]);
        }

        

        cnt = 0;
        
        for(int i = 0 ; i < nums.size() ; i++) {

            if(temp[i] < a) continue;

            // cout << temp[i] << " " << temp[i-1] << "--" << cnt << "-->" << endl;
            
            if(temp[i] <= b) ans = (ans + cnt) % mod;

            // cout << ans << endl;

            if(temp[i] > b) cnt++;
        }

        // ans += cnt;

        return ans % mod;
    }
};