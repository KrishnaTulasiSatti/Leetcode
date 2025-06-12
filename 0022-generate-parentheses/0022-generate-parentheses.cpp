class Solution {
public:

vector<string>res;

void fun(string s,int open,int close,int n) {
    if(open == n && close == n) {
        res.push_back(s);
        return;
    }

    // If open < n then we can add '('

    if(open < n) {
        fun(s+'(',open+1,close,n);
    }

    // close < open then only we can add ')'

    if(close < open && close < n) {
        fun(s+')',open,close+1,n);
    } 
}
    vector<string> generateParenthesis(int n) {
        string s="";
        fun(s,0,0,n);
        return res;
    }
};