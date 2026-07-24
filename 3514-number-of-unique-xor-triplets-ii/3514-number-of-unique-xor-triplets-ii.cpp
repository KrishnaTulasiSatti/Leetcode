class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        int n = nums.size();

        unordered_set<int>st;
        unordered_set<int>st2(nums.begin(),nums.end());

        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j < n ; j++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }

        vector<int>xr(st.begin(),st.end());
        vector<int>temp(st2.begin(),st2.end());

        // cout << xr.size() << endl;

        unordered_set<int>res;

        for(int i = 0 ; i < temp.size() ; i++) {
            for(int j = 0 ; j < xr.size() ; j++) {
                res.insert(temp[i] ^ xr[j]);
                
            }
        }

        return res.size();
    }

};