class Solution {
public:
    bool winnerOfGame(string colors) {
        int maxiA = 0;
        int maxiB = 0;
        
        int a = 0 , b = 0;
        for(int i = 0 ; i < colors.size() ; i++) {
            if(colors[i] == colors[i+1] && colors[i] == 'A') a++;
            else if(colors[i] != colors[i+1] && colors[i] == 'A') {
                maxiA += (a-1) < 0 ? 0 : (a-1);
                a = 0;
            }
            
            if(colors[i] == colors[i+1] && colors[i] == 'B') b++;
            else if(colors[i] != colors[i+1] && colors[i] == 'B') {
                maxiB += (b-1) < 0 ? 0 : (b-1);
                b = 0;
            }



        }
        cout << maxiA << " " << maxiB;
        if(maxiA > maxiB) return true;
        return false;
    }
};