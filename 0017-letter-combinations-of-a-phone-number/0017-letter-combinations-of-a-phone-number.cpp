class Solution {
public:

    vector<string>ans;

    int n;

    void fun(string& digits,int i,string& temp,vector<string>& v) {

        if(i == n) {
            ans.push_back(temp);
            return;
        }

        for(auto& it : v[digits[i]-'0']) {
            temp += it;
            fun(digits,i+1,temp,v);
            temp.pop_back();
        }


    }

    vector<string> letterCombinations(string digits) {

        vector<string>v = {"1","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        n = digits.size();

        string temp = "";
        fun(digits,0,temp,v);

        return ans;


    }
};