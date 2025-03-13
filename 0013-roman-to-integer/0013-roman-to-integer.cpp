class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
       // m['V'] = 5;
         int res = 0;
        for(int i = 0 ; i < s.size() ; ) {
            int a = m[s[i]];
            int b = m[s[i+1]];

            if(a >= b) {
                res+=a;
            }
            else {
                res+=(b-a);
                i++;
            }
            i++;
            cout << res << endl;
        }
        return res;
    }
};