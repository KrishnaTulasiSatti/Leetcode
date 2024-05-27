class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>st;
        vector<string>res;
        int i = 1;
        if(target[0] == 1) {
            st.push(1);
            res.push_back("Push");
        } 
        else{
           st.push(0);
           res.push_back("Push");
           res.push_back("Pop"); 
        }
        i++;
        while(!st.empty() && st.top() != target.back()) {
            st.push(i);
            if(find(target.begin(),target.end(),i) == target.end()) {
                 st.pop();
                 res.push_back("Push");
                 res.push_back("Pop");
            }
            else  res.push_back("Push");
            i++;
        }
        return res;
    }
};