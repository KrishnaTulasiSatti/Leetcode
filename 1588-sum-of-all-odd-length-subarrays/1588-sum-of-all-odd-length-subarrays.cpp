class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int sum = 0;

        int n = arr.size();

        for(int i = 0 ; i < arr.size() ; i++) {
            sum += ceil(((n-i)/2.0) * (i+1)) * arr[i];
        }

        return sum;
    }
};