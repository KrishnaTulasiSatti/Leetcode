class Solution {
public:
string fun(string s,int carry) {
    
    string res = "";
    reverse(s.begin(),s.end());

    int i = 0;

    while(i < s.size() || carry) {
        int sum = 0;
        if(i < s.size()) sum = (s[i++]-'0');
        sum += carry;
        if(sum < 2) {
            res += (sum+'0');
            carry = 0;
        }
        else {
            res += '0';
            carry = 1;
        }

        // cout << res << endl;

    }

   
    reverse(res.begin(),res.end());
    return res;


}
    int numSteps(string s) {
        
        string temp = s;

        int cnt = 0;
        
        while(temp.size() != 1) {

            int n = temp.size();
            if(temp[n-1] == '1') {
                temp = fun(temp,1);
            }
            else temp.pop_back();
            
            cout << temp << endl;
            cnt++;
        }

        return cnt;


    }
};