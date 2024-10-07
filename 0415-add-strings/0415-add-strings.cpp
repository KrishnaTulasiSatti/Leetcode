class Solution {
public:
    string addStrings(string num1, string num2) {
       string sum = "";
       int i = num1.size()-1;
       int j = num2.size()-1;
       int carry = 0;
       while(i >= 0 && j >= 0) {
           int s = (num1[i]-'0')+(num2[j]-'0')+carry;
           if(s >= 10) {
              carry = s/10;
              s = s % 10;
           }
           else {
            carry = 0;
           }
           sum+=(s+'0');
           i--;
           j--;
       }   
       while(i >= 0) {
          int s = (num1[i]-'0')+carry;
          if(s >= 10) {
              carry = s/10;
              s = s % 10;
           }
           else {
            carry = 0;
           }
           sum+=(s+'0');
           i--;
       }
         while(j >= 0) {
          int s = (num2[j]-'0')+carry;
          if(s >= 10) {
              carry = s/10;
              s = s % 10;
           }
           else {
            carry = 0;
           }
           sum+=(s+'0');
           j--;
       }
       if(carry) sum+=(carry+'0');
       reverse(sum.begin(),sum.end());
       return sum;
    }
};