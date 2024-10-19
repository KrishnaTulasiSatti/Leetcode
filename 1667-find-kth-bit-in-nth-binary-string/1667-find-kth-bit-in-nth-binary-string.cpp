class Solution {
public:
string fun(int n,string s) {
    if(n == 0) return s;
    string a = s+"1";
    for(int i = s.size()-1 ; i >= 0 ; i--) {
        if(s[i] == '1') a+="0";
        else a+="1";
    }
    return fun(n-1,a);
}
    char findKthBit(int n, int k) {
        string ans = fun(n,"0");
        return ans[k-1];
    }
};