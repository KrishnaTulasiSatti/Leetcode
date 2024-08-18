class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        for(int i = 0 ; i < digits.size() ; i++) {
            int x = digits[i]+carry;
            if(x < 10) {
                carry = 0;
                digits[i] = x;
            }
            else{
                int a = x % 10;
                int b = x/10;
                digits[i] = a;
                carry = b;
            }
        }
        if(carry) digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};