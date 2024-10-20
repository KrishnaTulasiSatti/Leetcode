class Solution {
public:
bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}
    int maxVowels(string s, int k) {
        int maxi = 0;
        for(int i = 0 ; i < k ; i++) {
            if(isVowel(s[i])) maxi++;
        }
        int l = 0;
        int r = k;
        int cnt = maxi;
        while(r < s.size()) {
            if(isVowel(s[r])) cnt++;
            if(isVowel(s[l])) cnt--;
            maxi = max(maxi,cnt);
            l++;
            r++;
        }
        return maxi;
    }
};