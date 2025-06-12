class Solution {
public:

double BE(double x,long long n) {
    if(n == 0) return 1;

    double ans = BE(x,n/2);

    if(n % 2 == 0) {
        return ans*ans;
    }
    else {
        return ans*ans*x;
    }
}
    double myPow(double x, int n) {
        long long nn = n;
        if(nn < 0) return 1/BE(x,-1*nn);
        return BE(x,nn);
    }
};