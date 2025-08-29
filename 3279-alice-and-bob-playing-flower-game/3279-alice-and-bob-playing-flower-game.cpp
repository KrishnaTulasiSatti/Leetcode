class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd = n/2;
        long long even = n/2;
        if(n % 2) odd++;

        long long odd2 = m/2;
        long long even2 = m/2;
        if(m % 2) odd2++;

        long long ans = 1LL*(odd*even2) + 1LL*(odd2*even);
        return ans;
    }
};