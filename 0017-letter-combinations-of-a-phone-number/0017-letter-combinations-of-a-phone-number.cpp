class Solution {
public:

vector<string>res;

void fun(string digits,int ind,int n,string temp,vector<string>&s) {
    if(ind == n) {
        if(temp != "") res.push_back(temp);
        return;
    }

    int num = digits[ind]-'0';

    for(int i = 0 ; i < s[num-2].size() ; i++) {
        temp += s[num-2][i];
        fun(digits,ind+1,n,temp,s);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>s = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string temp = "";

        fun(digits,0,digits.size(),temp,s);

        return res;

    }
};