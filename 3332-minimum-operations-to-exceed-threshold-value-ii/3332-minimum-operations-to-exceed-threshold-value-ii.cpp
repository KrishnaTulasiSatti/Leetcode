class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long>st;
        for(int i = 0 ; i < nums.size() ; i++) {
            st.insert(nums[i]);
        }
        
        int c = 0;
        while(*st.begin() < k) {
            long long a = *st.begin();
            st.erase(st.find(a));
            long long b = *st.begin();
            st.erase(st.find(b));
            st.insert(min(a,b)*2+max(a,b));
            c++;
        }
        return c;
    }
};