class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {

        vector<int>nse(arr.size());

        stack<int>st1;

        for(int i = arr.size()-1 ; i >= 0 ; i--) {

            while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();

            if(st1.empty()) nse[i] = arr.size();
            else nse[i] = st1.top();

            st1.push(i);
        }

        // for(auto it : nse) {
        //     cout << it << " ";
        // }

        stack<int>st2;

        vector<int>pse(arr.size());

        for(int i = 0 ; i < arr.size() ; i++) {

            while(!st2.empty() && arr[st2.top()] >= arr[i]) st2.pop();

            if(st2.empty()) pse[i] = -1;
            else pse[i] = st2.top();

            st2.push(i);

        }

        int ans = 0;

        for(int i = 0 ; i < arr.size() ; i++) {

            ans = max(ans,arr[i] * (nse[i]-pse[i]-1));
            
        }
       

        // for(auto it : pse) {
        //     cout << it << " ";
        // }

        return ans;


    }
};