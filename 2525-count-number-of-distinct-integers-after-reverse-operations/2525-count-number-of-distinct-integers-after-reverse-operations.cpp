class Solution {
public:
int Palindrome(int n) {
    int rev = 0;
    while(n) {
        int ld = n % 10;
        rev = rev*10+ld;
        n/=10;
    }
    return rev;
}
    int countDistinctIntegers(vector<int>& nums) {
        int cnt = 0;
        vector<int>arr = nums;
        for(auto it : nums) {
            arr.push_back(Palindrome(it));

        }
        set<int>s(arr.begin(),arr.end());
        return s.size();
    }
};