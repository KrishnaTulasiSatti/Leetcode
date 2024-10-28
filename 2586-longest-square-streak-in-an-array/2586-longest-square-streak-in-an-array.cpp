class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>m;;
        for(auto it : nums) m[it]++;
        int maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            long long a = nums[i];
            int cnt = 0;
            while(m[a] > 0 && a <= 100000) {
                cnt++;
                a = a*a;
            }
            maxi = max(maxi,cnt);
        }
        return maxi <= 1 ? -1 : maxi;
    }
};