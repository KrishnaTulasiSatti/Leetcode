class Solution {
public:
vector<string>res;

void fun(int open,string str,int close) {
    if(open == 0 && close == 0) {
        res.push_back(str);
        return;
    }

    if(open > 0) fun(open-1,str+'(',close);
    if(close > open) fun(open,str+')',close-1);
}
    vector<string> generateParenthesis(int n) {
        string str = "(";
        fun(n-1,str,n);

        return res;

    }
};