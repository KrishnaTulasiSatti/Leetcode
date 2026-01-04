class Solution {
public:

    vector<string>ans;

    void fun(int i,int n,string& temp,vector<int>&vis) {

        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0 ; i < n ; i++) {
            if(vis[i] == 1) continue;

            vis[i] = 1;

            temp += ((i+1) + '0');
            fun(i+1,n,temp,vis);
            temp.pop_back();

            vis[i] = 0;
        }

    }

    int Fact(int n) {
        int f = 1;
        for(int i = 1 ; i <= n ; i++) f *= i;
        return f;
    }

    string getPermutation(int n, int k) {

     
       vector<int>vis(n,0);

       k = k-1;
       
       int fact = Fact(n-1);

       int num = k/fact;

       string temp = to_string(num+1);
       vis[num] = 1; 
       
       fun(num,n,temp,vis);

       sort(ans.begin(),ans.end());

       return ans[k % fact];

    }
};