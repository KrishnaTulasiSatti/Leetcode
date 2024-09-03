class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            int a = s[i]-'a'+1;
            num+=(a/10)+(a%10);
        }
       // cout<<num<<endl;
        int res = num;
        k--;
        while(k--) {
            res = 0;
            while(num) {
              res+=(num % 10);
              num/=10;
            }
            num = res;
        }
        return res;
    }
};