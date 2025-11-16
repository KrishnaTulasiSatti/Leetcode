class Solution {
public:
    int numSub(string s) {
        long long ans = 0;

        int ones = 0;

        int mod = 1e9+7;

        for(int i = 0 ; i < s.size() ; i++) {

            if(s[i] == '0') {
                long long cnt = 1LL*ones*(ones+1);
                long long res = (cnt % mod)/2;
                ans += res;
                ones = 0;
            }
            else ones++;
        }

        long long cnt = 1LL*ones*(ones+1);
        long long res = (cnt % mod)/2;
        ans += res;

        return ans % mod;
    }
};