class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        long long ans = 0;

        vector<int>temp;
        temp.push_back(nums[0]);

        for(int i = 1 ; i < colors.size() ; i++) {

            if(colors[i] != colors[i-1]) {
                long long odd = 0 , even = 0;
                for(int j = 0 ; j < temp.size() ; j++) {
                    if(j % 2) odd += temp[j];
                    else even += temp[j];
                }
                ans += max(odd,even);

                temp = {};
            }
            temp.push_back(nums[i]);
            
        }

        long long odd = 0 , even = 0;
        for(int j = 0 ; j < temp.size() ; j++) {
            if(j % 2) odd += temp[j];
            else even += temp[j];
        }
        ans += max(odd,even);

        return ans;
    }
};