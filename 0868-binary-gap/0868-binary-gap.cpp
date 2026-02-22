class Solution {
public:
    int binaryGap(int n) {
        
        string str = "";

        while(n != 0) {
            str += ((n % 2) + '0');
            n/=2;
        }

        int s = 0;

        int maxi = 0;
        int cnt = 0;

        for(int i = 0 ; i < str.size() ; i++) {
            if(str[i] == '1' && s == 0) s = 1;
            else if(str[i] == '1' && s == 1) {
                cnt++; 
                maxi = max(maxi,cnt);
                s = 0;
                i--;
                cnt = 0;
            } 
            else if(s == 1 && str[i] == '0') cnt++;

            // cout << cnt << endl;
        }

        return maxi;


    }
};