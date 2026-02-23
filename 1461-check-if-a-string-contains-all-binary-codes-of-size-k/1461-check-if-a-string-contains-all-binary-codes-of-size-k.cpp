class Solution {
public:
    bool hasAllCodes(string s, int k) {

        if(k > s.size()) return false;
        
        string str = "";

        for(int i = 0 ; i < k ; i++) str += s[i];

        set<string>st;

        st.insert(str);

        int l = 0;
        int r = k;

        while(r < s.size()) {
            str.erase(0,1);
            str += s[r];

            st.insert(str);
            l++;
            r++;
        }

        return st.size() == pow(2,k);


    }
};