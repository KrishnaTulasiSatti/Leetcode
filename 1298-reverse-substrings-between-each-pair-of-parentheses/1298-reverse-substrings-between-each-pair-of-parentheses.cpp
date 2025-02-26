class Solution {
public:
    string reverseParentheses(string s) {

        stack<pair<char,int>>st;

        vector<char>v(s.size(),' ');

        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '(') st.push({s[i],i});
            else if(s[i] == ')') {
                int a = st.top().second;
                // for(auto it : v) {
                //     cout << it << "-";
                // }
              //  cout << endl;
                reverse(v.begin()+a+1,v.begin()+i+1);
                st.pop();
                
            }
            else v[i]=s[i];
        }

        string res = "";

        for(int i = 0 ; i < v.size() ; i++) {
            if(v[i] != ' ') res+=v[i];
        }
        return res;

    }
};