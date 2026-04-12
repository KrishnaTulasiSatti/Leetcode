class Solution {
public:

    vector<int>primes;
    vector<bool> isPrime;

    void sieve(int n) {

        isPrime.resize(n+1,true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
    }
    int minOperations(vector<int>& nums) {

        sieve(1e5+100);
        
        int ops1 = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(i % 2 == 0) {
                if(isPrime[nums[i]] == false) {
                    int np = *lower_bound(primes.begin(),primes.end(),nums[i]);
                    ops1 += abs(np-nums[i]);
                } 
            }
            else {
                // if(nums[i] == 1) ops1 += 1;
                if(isPrime[nums[i]] == true) {
                    if(nums[i] == 2) ops1 += 2;
                    else ops1 += 1;
                }
            }
        }

        return ops1;

        


    }
};