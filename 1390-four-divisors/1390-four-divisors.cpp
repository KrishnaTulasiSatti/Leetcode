class Solution {
public:

    int count(int num) {
        int cnt = 0;
        int sum = 0;

        for(int i = 1 ; i*i <= num ; i++) {

            if(num % i == 0) {
                cnt+=2;
                sum += i;
                sum += (num/i);
                //cout << i << " " << num/i << " ";
            }
            if(i == (num*1.0/i)) {
                 cnt--;
                 sum += i;
            }

        }

       // cout << num << " " << cnt << endl;
        if(cnt == 4) return sum;
        return 0;

    }
    int sumFourDivisors(vector<int>& nums) {

        int sum = 0;
        
        for(auto it : nums) {
            sum += count(it);
        }

        return sum;
    }
};