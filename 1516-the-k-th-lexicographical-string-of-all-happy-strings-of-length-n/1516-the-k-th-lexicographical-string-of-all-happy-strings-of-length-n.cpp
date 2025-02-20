class Solution {
public:

vector<string>res;

void fun(string s,int n) {

    if(s.size() == n) {
        res.push_back(s);
        return;
    }

    int l = s.size()-1;
    if(s[l] == 'a') {
        fun(s+'b',n);
        fun(s+'c',n);
    }
    else if(s[l] == 'b') {
        fun(s+'a',n);
        fun(s+'c',n);
    }
    else{
        fun(s+'a',n);
        fun(s+'b',n);
    }


}
    string getHappyString(int n, int k) {
        fun("a",n);
        fun("b",n);
        fun("c",n);

        sort(res.begin(),res.end());

        if(k > res.size()) return "";
        return res[k-1];
       
    }
};