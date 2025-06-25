class Solution {
public:

int res = 0;
bool isUnique(string s) {
    set<char>st;
    for(auto it : s) {
        st.insert(it);
    }

    return st.size() ==  s.size();
}
void fun(vector<string>&arr,int i,string s) {
    int n = arr.size();

    if(i == n) {
        if(isUnique(s)) {
            int m = s.size();
            res = max(res,m);
        }
        return;
    }

    if(!isUnique(s)) return;

    fun(arr,i+1,s+arr[i]);
    
    fun(arr,i+1,s);

}
    int maxLength(vector<string>& arr) {
        string s = "";
        fun(arr,0,s);
        return res;
    }
};