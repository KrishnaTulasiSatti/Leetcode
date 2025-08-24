class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even = 2;
        int odd = 1;

        int i = 1;

        int o = 1;
        int e = 2;

        while(i < n) {
            e += 2;
            o += 2;
            even += e;
            odd += o;
            i++;
        }

        cout << odd << " " << even << endl;

        return gcd(odd,even);
    }
};