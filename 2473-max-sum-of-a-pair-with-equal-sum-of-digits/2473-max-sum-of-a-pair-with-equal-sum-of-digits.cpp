class Solution {
public:
long long digitSum(long long n) {
    long long sum = 0;
    while(n > 0) {
        int ld = n % 10;
        sum+=ld;
        n/=10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
       unordered_map<long long,multiset<long long>>m;
       long long maxi = -1;
       for(int i = 0 ; i < nums.size() ; i++) {
         long long sum = digitSum(nums[i]);
       //  cout<<sum<<endl;
         m[sum].insert(nums[i]);
         if(m[sum].size() >= 2) {
            long long last = *m[sum].rbegin();
            m[sum].erase(m[sum].find(last));
            long long next = *m[sum].rbegin();
            m[sum].insert(last);
            maxi = max(maxi,last+next);
         }

       }   
       return maxi;
    }
};