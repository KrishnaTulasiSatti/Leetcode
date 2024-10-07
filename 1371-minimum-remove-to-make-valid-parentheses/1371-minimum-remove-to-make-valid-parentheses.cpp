class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i = 0 ; i < s.size() ;i++) {
            if(s[i] == '(' || s[i] == ')') {
                if(st.empty()) st.push({s[i],i});
                else if(st.top().first == '(' && s[i] == ')') st.pop();
                else st.push({s[i],i});
            }
        }
        if(st.empty()) return s;
        while(!st.empty()) {
            s.erase(st.top().second,1);
            st.pop();
        }
        return s;
    }
};