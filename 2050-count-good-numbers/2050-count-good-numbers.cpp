class Solution {
public:
 const int mod = 1e9+7;

 long long BE(long long a,long long b) {
    if(b == 0) return 1;

    long long ans = BE(a,b/2);

    if(b % 2 == 0) {
        return ((ans % mod) * (ans % mod)) % mod;
    } 
    else {
        return ((ans % mod) * (ans % mod) * a) % mod;
    }
 }
    int countGoodNumbers(long long n) {
        long long even = n/2;
        if(n % 2) even++;
        long long odd = n/2;

        long long ans = (BE(5,even) % mod)*(BE(4,odd) % mod);

        return ans % mod;
    }
};