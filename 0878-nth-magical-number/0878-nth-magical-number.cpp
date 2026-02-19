class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        
        long long low = 1;
        long long high = 1LL*n * max(a,b);

        long long ans = 0;

        const int mod = 1e9+7;

        while(low <= high) {

            long long mid = (low + high)/2;

            long long div_a = mid/a;
            long long div_b = mid/b;

            long long lcm = (a*b)/__gcd(a,b);
            long long div_c = mid/lcm;

            long long cnt = div_a + div_b - div_c;

            if(cnt >= n) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;

        }

        return ans % mod;
    }
};