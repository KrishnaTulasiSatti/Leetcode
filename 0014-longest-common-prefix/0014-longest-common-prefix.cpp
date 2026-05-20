class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());

        if(strs.size() == 1) return strs[0];

        int n = strs.size();

        string s1 = strs[0];
        string s2 = strs[n-1];

        string ans = "";
        int i = 0;
        int j = 0;

        while(i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
            ans += s1[i];
            i++;
            j++;
        }

        return ans;

        return "";
    }
};