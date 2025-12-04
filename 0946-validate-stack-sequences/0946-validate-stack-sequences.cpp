class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int>st;

        int i = 0,j = 0;

        int n = popped.size();
        
        while(j < n && i < n) {

            if(pushed[i] != popped[j]) {
                if(!st.empty()) {
                    if(st.top() == popped[j]) {
                        st.pop();
                        j++;
                    }
                    else {
                        st.push(pushed[i]);
                        i++;
                    }
                }
                else {
                    st.push(pushed[i]);
                    i++;
                }
            }
            else {
                i++;
                j++;
            }
        }

        // cout << st.size() << endl;

        while(j < n && st.top() == popped[j]) {
            st.pop();
            j++;
        }

        if(st.empty()) return true;
        return false;


    }
};