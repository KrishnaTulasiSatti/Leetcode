class Solution {
public:
int fun(string str,int k,char ch) {
    int l = 0;
    int r = 0;
    int maxi = 0;
    vector<int>v(26,0);
    while(r < str.size()) {
        v[str[r]-'A']++;
        if(str[r] == ch) {
            while(v[str[r]-'A'] > k) {
                v[str[l]-'A']--;
                l++;
            }
        }
        maxi = max(maxi,r-l+1);
        r++;

    }
    return maxi;
}
    int maxConsecutiveAnswers(string answerKey, int k) {

        int a = fun(answerKey,k,'F');
        int b = fun(answerKey,k,'T');
        return max(a,b);
    }
};