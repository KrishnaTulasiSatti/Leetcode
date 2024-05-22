class Solution {
public:
    int differenceOfSums(int n, int m) {
         int x = n/m;
         int num1 = m*x*(x+1)/2;
         int num2 = (n*(n+1)/2)-num1;
         return num2-num1;
    }
};