class Solution {
public:
bool isValid(string s) {
    for(int i = 1 ; i < s.size() ; i++) {
        if(s[i-1] == '0' && s[i] == '0') return false;
    }
    return true;
}
    vector<string> validStrings(int n) {
        vector<string>res;
        for(int i = 0 ; i < pow(2,n) ; i++) {
            string bin = "";
            for(int j = 0 ; j < n ; j++) {
                 int mask = i & (1 << j);  // Kth bit set --> n & (1 << k)
                 if(mask) bin+='1';
                 else bin+='0';
            }
            if(isValid(bin)) res.push_back(bin);
        }
        return res;
    }
};