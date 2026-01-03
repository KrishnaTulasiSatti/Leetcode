class Solution {
public:
    vector<string>ans;

    void fun(int i,int n,string& str) {

        if(i >= n) {
            ans.push_back(str);
            return;
        }

        char last = str.back();

        if(last == '0') {
            str += '1';
            fun(i+1,n,str);
            str.pop_back();
        }
        else {
            str += '0';
            fun(i+1,n,str);
            str.pop_back();

            str += '1';
            fun(i+1,n,str);
            str.pop_back();
        }

       

    }
    vector<string> validStrings(int n) {

        string str = "0";
        fun(1,n,str);

        str = "1";
        fun(1,n,str);

        return ans;
    }
};