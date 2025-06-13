class Solution {
public:

int cnt = 0;

void fun(string s,int n,vector<int>&vis) {

    if(s.size() <= n) cnt++;

    if(s.size() > n) return; 

    for(int i = 0 ; i <= 9 ; i++) {
        if(s.size() == 0 && i == 0) continue;
        if(vis[i] == -1) {
            s+=(i+'0');
            vis[i] = 1;
            fun(s,n,vis);
            vis[i] = -1;
            s.pop_back();
        }
       
    }


}
    int countNumbersWithUniqueDigits(int n) {
        vector<int>vis(10,-1);
        string s = "";
        fun(s,n,vis);
        return cnt;
    }
};