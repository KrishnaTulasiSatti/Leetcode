class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int a = 0;
        int b = 0;
        map<vector<int>,int>m;
        for(int i = 0 ; i < obstacles.size() ; i++) {
            m[obstacles[i]]++;
        }
        int xp = 0;
        int xn = 0;
        int yp = 1;
        int yn = 0;
        int maxi = INT_MIN;
        for(int i = 0 ; i < commands.size() ; i++) {
            if(commands[i] < 0) {
                if(yp == 1) {
                    if(commands[i] == -1) {
                        yp = 0, xp = 1,xn = 0 , yn = 0;
                    }
                    else{
                        yp = 0 , xp = 0 , xn= 1,yn = 0;
                    }
                }
                else if(xp == 1) {
                    if(commands[i] == -1) {
                        yp = 0, xp = 0,xn = 0 , yn = 1;
                    }
                    else{
                        yp = 1 , xp = 0 , xn= 0,yn = 0;
                    }
                }
                else if(yn == 1) {
                     if(commands[i] == -1) {
                        yp = 0, xp = 0,xn = 1 , yn = 0;
                    }
                    else{
                        yp = 0 , xp = 1 , xn= 0,yn = 0;
                    }
                }
                else {
                     if(commands[i] == -1) {
                        yp = 1, xp = 0,xn = 0 , yn = 0;
                    }
                    else{
                        yp = 0 , xp = 0 , xn= 0,yn = 1;
                    }
                }
            }
            else{
            if(yp == 1) {
                while(commands[i]--){
                    b++;
                   
                    if(m[{a,b}] >= 1) {
                        b--;
                        break;
                    }
                     maxi = max(maxi,(a*a)+(b*b));
                }
            }
            else if(xp == 1) {
                while(commands[i]--) {
                    a++;
                    if(m[{a,b}] >= 1) {
                        a--;
                        break;
                    }
                     maxi = max(maxi,(a*a)+(b*b));
                }
            }
            else if(yn == 1) {
                 while(commands[i]--) {
                    b--;
                    if(m[{a,b}] >= 1) {
                        b++;
                        break;
                    }
                     maxi = max(maxi,(a*a)+(b*b));
                }
            }
            else{
                 while(commands[i]--) {
                    a--;
                    if(m[{a,b}] >= 1) {
                        a++;
                        break;
                    }
                     maxi = max(maxi,(a*a)+(b*b));
                }
            }
            cout<<a<<" "<<b<<endl;
            }
        }
        if(maxi == INT_MIN) return 0;
       return maxi;
    }
};