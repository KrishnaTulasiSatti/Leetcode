class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long sum1 = 0;

        long long sum2 = 0;

        int cnt1 = 0;

        int cnt2 = 0;

        for(auto it : nums1) {
            sum1 += it;
            if(it == 0) cnt1++;
        }

        for(auto it : nums2) {
            sum2 += it;
            if(it == 0) cnt2++;
        }

        cout << sum1 << " " << sum2 << endl;

        long long req1 = sum1+cnt1;

        long long req2 = sum2+cnt2;

        if(req1 == req2 && (cnt1 == 0 && cnt2 == 0)) return req1;

        if(req1 > req2) {
            if(cnt2 == 0 || cnt2 > req1) return -1;

            return req1;

        }
        else {
            if(cnt1 == 0 || cnt1 > req2) return -1;

            return req2;
        }
        
        return req1;
        
    }
};