class Solution {
public:
const int mod = 1e9+7;

long long binexp(long long a,long long b) {
    
    if(b == 0) return 1;

    long long half = binexp(a,b/2);

    half = (half * half) % mod;

    if(b % 2) half = (a * half) % mod;

    return half;


}
    int countGoodNumbers(long long n) {
        long long even = n/2;
        long long odd = n/2;

        if(n % 2) even++;

        long long ans = binexp(5,even) % mod;
        
        long long ans1 = binexp(4,odd) % mod;

        return (ans * ans1) % mod;

    }
};