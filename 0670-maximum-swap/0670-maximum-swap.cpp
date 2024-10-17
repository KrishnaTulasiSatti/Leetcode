class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        string res = n;
        for(int i = 0 ; i < n.size() ; i++) {
            string t = n;
            for(int j = i+1 ; j < n.size() ; j++) {
                swap(t[i],t[j]);
                res = max(res,t);
                t = n;

            }
        }
        int ans = stol(res);
        return ans;
        
    }
};