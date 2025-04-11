class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low ; i <= high ; i++) {
            int n = log10(i)+1;
            if(n % 2 == 0) {
                int num = i;
                int sum = 0;
                for(int j = 0 ; j < n/2 ; j++) {
                    sum+=(num % 10);
                    num/=10;

                }
                for(int j = n/2 ; j < n ; j++) {
                    sum-=(num % 10);
                    num/=10;
                }

                if(sum == 0) cnt++;
            }
        }
        return cnt;
    }

};