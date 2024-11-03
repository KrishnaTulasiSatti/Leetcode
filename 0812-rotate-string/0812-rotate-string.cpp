class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0 ; i < s.size() ; i++) {
            string t = s;
            reverse(t.begin(),t.begin()+i);
            reverse(t.begin()+i,t.end());
            reverse(t.begin(),t.end());
           // cout<<t<<endl;
            if(t == goal) return true;
        }
        return false;
    }
};