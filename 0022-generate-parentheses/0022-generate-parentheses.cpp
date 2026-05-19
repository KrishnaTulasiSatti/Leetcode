class Solution {
public:

    vector<string>ans;

    void fun(int open,int close,string str) {

        if(open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }


        if(open == close) {
            str += "(";
            fun(open-1,close,str);
            str.pop_back();
        }
        else if(open == 0 && close > 0) {
            str += ')';
            fun(open,close-1,str);
            str.pop_back();
        }
        else {
            str += "(";
            fun(open-1,close,str);
            str.pop_back();

            str += ')';
            fun(open,close-1,str);
            str.pop_back();

        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        string str = "";

        fun(n,n,str);

        return ans;
    }
};