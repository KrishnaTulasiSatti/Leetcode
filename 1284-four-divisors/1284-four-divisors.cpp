class Solution {
public:

int count(int n) {
    int s = 0;
    int cnt = 0;
    for(int i = 1 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            int b = i;
            int c = n/i;
            if(b == c) {
                s+=b;
                cnt++;
            }
            else{
                s+=b;
                s+=c;
                cnt+=2;
            }
        }
    }
    return cnt == 4 ? s : 0;
}
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum+=count(nums[i]);
        }
        return sum;
    }
};