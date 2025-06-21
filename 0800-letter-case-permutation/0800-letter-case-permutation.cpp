class Solution {
public:

vector<string>ans;

void fun(string& s,int i,int n,string& temp) {

    if(i == n) {
        ans.push_back(temp);
        return;
    }

    if(s[i] >= 'a' && s[i] <= 'z') {
        temp[i] = s[i]-32;
        fun(s,i+1,n,temp);
        temp[i] = s[i]+32;

        fun(s,i+1,n,temp);

    }
    else fun(s,i+1,n,temp);


}
    vector<string> letterCasePermutation(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string temp = "";
        fun(s,0,s.size(),s);

        return ans;
    }
};