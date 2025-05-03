class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>t1;
        for(auto it : tops) {
            t1[it]++;
        }
        
        unordered_map<int,int>b1;
        for(auto it : bottoms) {
            b1[it]++;
        }

        int top_max = tops[0];
        int bot_max = bottoms[0];
        
        for(auto it : t1) {
            if(it.second > t1[top_max]) top_max = it.first;
        }

        for(auto it : b1) {
            if(it.second > b1[bot_max]) bot_max = it.first;
        }

        int mini1 = 0;
        int mini2 = 0;

        for(int i = 0 ; i < tops.size() ; i++) {
            if(tops[i] != top_max && bottoms[i] == top_max) mini1++; 
        }

        for(int i = 0 ; i < bottoms.size() ; i++) {
            if(bottoms[i] != bot_max && tops[i] == bot_max) mini2++; 
        }
        cout << top_max << " " << mini1 << endl;
        cout << bot_max << " " << mini2 << endl;

        if(t1[top_max]+mini1 != tops.size() && b1[bot_max]+mini2 != bottoms.size()) return -1;
       
       if(t1[top_max]+mini1 != tops.size()) mini1 =0;
       if(b1[bot_max]+mini2 != bottoms.size()) mini2 = 0;

       if(mini1 == 0) return mini2;
       if(mini2 == 0) return mini1;
       
    
       return min(mini1,mini2);




    }
};