class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        string res = "";
        int i = 0;
        for(i = 0 ; i < a.size() && i < b.size(); i++){
           int x = (a[i]-'0')+(b[i]-'0')+carry;
           if(x < 2) {
             res+=(x+'0');
             carry = 0;
           }
           else if(x == 2){
             res+='0';
             carry = 1;
           }
           else{
             res+='1';
             carry = 1;
           }
        }
        while(i < a.size()) {
            int x = (a[i]-'0')+carry;
           if(x < 2) {
            res+=(x+'0');
            carry = 0;
           }
           else{
             res+='0';
             carry = 1;
           }
           i++;
        }
        while(i < b.size()) {
            int x = (b[i]-'0')+carry;
           if(x < 2) {
             res+=(x+'0');
            carry = 0;
           }
           else{
             res+='0';
             carry = 1;
           }
           i++;
        } 
        if(carry) res+=(carry+'0');
        reverse(res.begin(),res.end());
        return res;
    }
};