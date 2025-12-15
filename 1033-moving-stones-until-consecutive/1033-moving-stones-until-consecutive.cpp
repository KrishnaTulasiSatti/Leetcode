class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        
        vector<int>v = {a,b,c};
        sort(v.begin(),v.end());
        a = v[0];
        b = v[1];
        c = v[2];

        int d1 = b-a-1;
        int d2 = c-b-1;

        int maxi = d1+d2;

        int mini = 0;
       
        if(d1 > 1 && d2 > 1) mini = 2;
        else if(d1 == 0 && d2 == 0) mini = 0;
        else mini = 1;

       return {mini,maxi};
    }
};