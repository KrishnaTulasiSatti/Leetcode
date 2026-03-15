class Solution {
public:
    long long countCommas(long long n) {
        
        string str = to_string(n);
        int len = str.size();

        long long ans = 0;

        if(len <= 3) return 0;
        else if(len <= 6) {
            ans = 1LL * abs(1e3-n) + 1;
        }
        else if(len <= 9) {
            ans = 1LL * abs(1e3-n) + 1;
            ans += 1LL * abs(1e6-n) + 1;
        }
        else if(len <= 12) {
            ans = 1LL * abs(1e3-n) + 1;
            ans += 1LL * abs(1e6-n) + 1;
            ans += 1LL * abs(1e9-n) + 1;
        }
        else if(len <= 15) {
            ans = 1LL * abs(1e3-n) + 1;
            ans += 1LL * abs(1e6-n) + 1;
            ans += 1LL * abs(1e9-n) + 1;
            ans += 1LL * abs(1e12-n) + 1;
        }
        else if(len <= 18) {
            ans = 1LL * abs(1e3-n) + 1;
            ans += 1LL * abs(1e6-n) + 1;
            ans += 1LL * abs(1e9-n) + 1;
            ans += 1LL * abs(1e12-n) + 1;
            ans += 1LL * abs(1e15-n) + 1;
        }
       
        return ans;





    }
};