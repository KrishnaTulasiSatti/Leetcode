class Solution {
public:


string mul(string num1,int digit) {

    string res = "";

    reverse(num1.begin(),num1.end());

    int carry = 0;

    for(int i = 0 ; i < num1.size() ; i++) {
        int pro = ((num1[i]-'0')*digit)+carry;
        res += ((pro % 10) + '0');
        carry = pro/10;
    }

    if(carry != 0) res += (carry+'0');

    return res;

}

string add_strings(string str1,string str2) {

    string res = "";

    int i = 0;
    int j = 0;

    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());

    int carry = 0;

    while(i < str1.size() || j < str2.size() || carry == 1) {
        int sum = 0;
        if(i < str1.size()) sum += (str1[i++]-'0');
        if(j < str2.size()) sum += (str2[j++]-'0');

        sum += carry;

        res += ((sum % 10)+'0');
        carry = sum/10;
        
    }

    reverse(res.begin(),res.end());
    return res;
}
    string multiply(string num1, string num2) {

        reverse(num2.begin(),num2.end());

        vector<string>vec;
        
        string prev = "0";

        for(int i = 0 ; i < num2.size() ; i++) {

            int digit = num2[i]-'0';

            string res = mul(num1,digit);

            reverse(res.begin(),res.end());

            for(int j = 0 ; j < i ; j++) res += "0";
            
            prev = add_strings(res,prev);

        }

        int i = 0;
        while(prev[i] == '0') i++;
        if(i == prev.size()) return "0";

        return prev;
    }
};