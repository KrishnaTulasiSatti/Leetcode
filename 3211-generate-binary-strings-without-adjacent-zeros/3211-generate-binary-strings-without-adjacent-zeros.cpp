class Solution {
public:

    vector<string>ans;

    void fun(int i,int n,string& str) {

        if(i == n) {
            ans.push_back(str);
            return;
        }

        // If the current char is '0' -- Only one call
        // Else two calls

        if(str.back() == '0') {
            str.push_back('1');
            fun(i+1,n,str);
            str.pop_back();
        }
        else{
            str.push_back('0');
            fun(i+1,n,str);
            str.pop_back();

            str.push_back('1');
            fun(i+1,n,str);
            str.pop_back();

        }
    }
    vector<string> validStrings(int n) {
        
        string s1 = "0";
        string s2 = "1";

        fun(1,n,s1);
        fun(1,n,s2);

        return ans;
    }
};