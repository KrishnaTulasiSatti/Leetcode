class Solution {
public:
vector<string>res;

void fun(vector<string>&ans,string& digits,int i,string str) {
    if(i == digits.size()-1) {
        res.push_back(str);
        return;
    }
    
    int ind = digits[i+1]-'0';
    for(int j = 0 ; j < ans[ind-2].size() ; j++) {
        fun(ans,digits,i+1,str+ans[ind-2][j]);
    }
}
    vector<string> letterCombinations(string digits) {

        vector<string>ans = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size() == 0) return {};
        int ind = digits[0]-'0';
        string str = "";
        for(int i = 0 ; i < ans[ind-2].size() ; i++) {
            fun(ans,digits,0,str+ans[ind-2][i]);
        }

        return res;
    }
};