class Solution {
public:
string change(string a) {
     if(a.size() <= 3) {
            int c = 4-a.size();
            reverse(a.begin(),a.end());
            while(c--) a+='0';
            reverse(a.begin(),a.end());
        }
        return a;
}
    int generateKey(int num1, int num2, int num3) {
        string a = to_string(num1);
        string b = to_string(num2);
        string c = to_string(num3);
        a = change(a);
        b = change(b);
        c = change(c);
        int a1,a2,a3;
        int res;
        string ans;
        for(int i = 0 ; i < 4 ; i++) {
            a1 = a[i]+'0';
            a2 = b[i]+'0';
            a3 = c[i]+'0';
            res = min({a1,a2,a3});
            ans+=(res-'0');
        }
        return stoi(ans);
    }
};