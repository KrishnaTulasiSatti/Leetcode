class Solution {
public:

int fun(int n) {
    if(n == 1) return 0;

    int c = 0 , a = 0 , b = 0;
    if(n % 2 == 0) {
        c = fun(n/2);
    }
    else {

        a = fun(n-1);
        b = fun(n+1);

    }
    

    return 1+c+min(a,b);
}
    int integerReplacement(int n) {

        if(n == INT_MAX) return 32;

        return fun(n);

    }
};