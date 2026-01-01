class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;

        int i = digits.size()-1;

        vector<int>res;

        while(i >= 0 || carry) {

            int sum = carry;

            if(i >= 0) sum += digits[i--];

            res.push_back(sum % 10);
            carry = sum/10;
        }

        reverse(res.begin(),res.end());

        return res;
    }
};