class Solution {
public:
int isTrue(int n) {
    int a = sqrt(n);
    if(a*a == n) return 1;
    return 0;
}
    bool judgeSquareSum(int c) {
       int r1 = sqrt(c);
       int r2 = -1*sqrt(c);
       int a = 0;
       while(a <= r1) {
          long long int x = a*a;
          if(isTrue(x) && isTrue(c-x)) return true;
          a++;
       }
       a = -1;
       while(a >= r2) {
         long long int x = a*a;
         if(isTrue(x) && isTrue(c-x)) return true;
         a--;
       }
       return false;
    }
};