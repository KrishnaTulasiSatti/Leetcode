class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            int a = s[i]-'a';
            sum += (26-a)*(i+1);
            cout << sum << endl;
        }
        return sum;
    }
};