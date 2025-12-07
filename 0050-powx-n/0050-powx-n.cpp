class Solution {
public:
    double fun(double x,long long n) {
        if(n == 0) return 1.0;
         
        if(n == 1) return x*1.0;

        if(n % 2) return x * fun(x,n-1);

        return fun(x*x,n/2);
    }
    double myPow(double x, int n) {
        int flag = false;

        if(n < 0) flag = true;

        long long num = n;
        
        if(flag) num = -1*num;

        double ans = fun(x,num);

        if(flag) return 1.0/ans;

        return ans;
    }
};