class Solution {
public:

vector<int>ans;

void fun(int n,int curr) {

    if(curr > n) return;

    ans.push_back(curr);

    for(int i = 0 ; i <= 9 ; i++) {
        fun(n,curr*10+i);
    }

}
    vector<int> lexicalOrder(int n) {

        for(int i = 1 ; i <= 9 ; i++) {
            fun(n,i);
        }

        return ans;
        
    }
};