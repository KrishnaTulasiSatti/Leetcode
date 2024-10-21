class Solution {
public:
bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    return false;
}
    int maxVowels(string s, int k) {
        int maxi = 0;
        int vowels = 0;
        for(int i = 0 ; i < k ; i++) {
            if(isVowel(s[i])) vowels++;
        }
        int l = 0;
        int r = k;
        maxi = vowels;
        while(r < s.size()) {
            if(isVowel(s[r])) vowels++;
            if(isVowel(s[l])) vowels--;
            maxi = max(maxi,vowels);
            l++;
            r++;
        }
        return maxi;
    }
};